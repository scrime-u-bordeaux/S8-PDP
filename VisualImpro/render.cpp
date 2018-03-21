/*
 ____  _____ _        _
| __ )| ____| |      / \
|  _ \|  _| | |     / _ \
| |_) | |___| |___ / ___ \
|____/|_____|_____/_/   \_\

The platform for ultra-low latency audio and sensor processing

http://bela.io

A project of the Augmented Instruments Laboratory within the
Centre for Digital Music at Queen Mary University of London.
http://www.eecs.qmul.ac.uk/~andrewm

(c) 2016 Augmented Instruments Laboratory: Andrew McPherson,
  Astrid Bin, Liam Donovan, Christian Heinrichs, Robert Jack,
  Giulio Moro, Laurel Pardue, Victor Zappi. All rights reserved.

The Bela software is distributed under the GNU Lesser General Public License
(LGPL 3.0), available here: https://www.gnu.org/licenses/lgpl-3.0.txt
*/

#include "ChannelsSettings.h"
#include "Echo.hpp"
#include "EffectManaging.hpp"
#include "ProcessMultiCorrel.hpp"
#include "ProcessMultiWriteWav.hpp"
#include <Bela.h>
#include <SampleStream.h>
#include <cmath>
#include <sys/time.h>
#include <time.h>
#include <vector>

/* Settings */

ChSettings gUserSet;
int gTotalTracks = 0;

SampleStream *sampleStream[NB_FILES_MAX];
AuxiliaryTask gFillBuffersTask;

/******* EFFECTS TASKS AND VARS *******/

bool gUseEffects = false;

int gEffSize = 0;

std::vector<std::vector<float>> gEffectBufferIn; // buffer filled in real time
std::vector<std::vector<float>> gEffectBufferInCopy;
std::vector<std::vector<float>> gEffectBufferOut;
int gSavedSamples = 0;
int gEffectProcessing = 0;

int gReadPointer = 0;
int gWritePointer = 0;
int gEffectStart = 1;

int gIndIn = 0;
int gIndOut = 0;
int gCopySize = 0;
int gLastSample = 0;

AuxiliaryTask gEffectTask;

void effect(std::vector<std::vector<float>> &In,
            std::vector<std::vector<float>> &Out) {
  assert(In.size() == gTotalTracks);
  int i;
  for (i = 0; i < gUserSet.nb_audio; i++) { // audio
    if (gUserSet.audioproc[i] == NULL) {
      In[i].swap(Out[i]);
    } else {
      gUserSet.audioproc[i]->apply(In[i], Out[i]);
    }
  }
  for (i = gUserSet.nb_audio; i < gUserSet.nb_audio + gUserSet.nb_analog;
       i++) { // analog
    if (gUserSet.analogproc[i - gUserSet.nb_audio] == NULL) {
      In[i].swap(Out[i]);
    } else {
      gUserSet.analogproc[i - gUserSet.nb_audio]->apply(In[i], Out[i]);
    }
  }
  for (i = gUserSet.nb_audio + gUserSet.nb_analog; i < gTotalTracks;
       i++) { // files
    if (gUserSet.fileproc[i - gUserSet.nb_audio - gUserSet.nb_analog] == NULL) {
      In[i].swap(Out[i]);
    } else {
      gUserSet.fileproc[i - gUserSet.nb_audio - gUserSet.nb_analog]->apply(
          In[i], Out[i]);
    }
  }
}

void processEffect() {
  genEffect(gEffectBufferInCopy, gIndIn, gEffectBufferOut, gIndOut, gCopySize,
            2 * gEffSize, effect); // from EffectManaging.hpp
  gEffectProcessing = 0;
  if (gEffectStart == 1) {
    gLastSample = 2 * gEffSize - 1;
    gEffectStart = 0;
  } else {
    gLastSample = (gLastSample + gCopySize) % (2 * gEffSize);
  }
}

/****** SAMPLING *****/

int gSampleFactor = 1;

/******* MIXING *******/

std::vector<float> gMeanCorrel;

//std::vector<float>* gMixBuffer = &gMeanCorrel;

/****** PROCESSING (MATRIX) TASKS AND VARS *******/

int gBufferProLen = 0;
int gNumStreams = NB_FILES_MAX;
int gNumAnalog = 0;
int gNumAudio = 0;
std::vector<std::vector<float>> gProcessBuffer; // buffer filled in real time
std::vector<std::vector<float>> gProcessBufferCopy; // buffer used to process

void fillBuffers() {
  for (int i = 0; i < gUserSet.nb_files; i++) {
    if (sampleStream[i]->bufferNeedsFilled())
      sampleStream[i]->fillBuffer();
  }
}

int gFillPosition = -1; // last position that was filled. When gFillPosition =
                        // BUFFERLEN-1, buffer should be analyzed and empty'd

AuxiliaryTask gProcessBufferTask;
bool gBufferProcessed = 1;

ProcessMultiCorrel *p;

struct timeval tv;
struct timeval tv2;

void processBuffer() {
  if (gBufferProcessed == 0) {
    p->process(gProcessBufferCopy, gMeanCorrel, gUserSet.conn);
    gBufferProcessed = 1;
  }
}


/*
Order in Buffers :
- from 0 to gNumStreams-1 : files
- from gNumStreams to gNumStreams + gNumAnalog -1 : analog
- from gNumStreams + gNumAnalog to gNumStreams + gNumAnalog + gNumAudio : audio
*/

bool setup(BelaContext *context, void *userData) {

  /* Dynamic linking */

  /********************************/
  gUserSet = *((ChSettings *)userData);
  gTotalTracks = gUserSet.nb_files + gUserSet.nb_audio + gUserSet.nb_analog;
  gNumStreams = gUserSet.nb_files;
  gNumAudio = gUserSet.nb_audio;
  gNumAnalog = gUserSet.nb_analog;
  gBufferProLen = gUserSet.buffer_len;
  gEffSize = gUserSet.effect_len;
  gUseEffects = gUserSet.useeffects;
  gSampleFactor = gUserSet.sample_factor;

  p = gUserSet.proc;
  gUserSet.conn.init();

  // Initialize effect buffers
  std::vector<std::vector<float>> effbuffer(
      gTotalTracks, std::vector<float>(2 * gEffSize, 0.0f));
  std::vector<std::vector<float>> effbufferIn(
      gTotalTracks, std::vector<float>(gEffSize, 0.0f));
  gEffectBufferOut = effbuffer;
  gEffectBufferIn = gEffectBufferInCopy = effbufferIn;

  // Initialize process buffers
  std::vector<std::vector<float>> procbuffer(
      gTotalTracks, std::vector<float>(gUserSet.buffer_len, 0.0f));
  gProcessBuffer = procbuffer;
  gProcessBufferCopy = procbuffer;
  for (int i = 0; i < gNumStreams; i++) {
    int nbchan = getChannelNumber(gUserSet.filenames[i]);
    sampleStream[i] = new SampleStream(gUserSet.filenames[i].c_str(), nbchan,
                                       FILE_BUFFER_LEN);
  }
  for (int i = 0; i < gUserSet.nb_files; i++) {
    sampleStream[i]->togglePlayback(1);
  }

  // Initialize mix Buffer
  
  std::vector<float> mixbuffer(gTotalTracks, 0.0f);
  gMeanCorrel = mixbuffer;

  // Print info
  cout << endl << endl << "------ Settings ------" << endl;
  cout << "* "
       << "Files : " << gNumStreams << endl;
  cout << "* "
       << "Standard Audio Tracks : " << gNumAudio << endl;
  cout << "* "
       << "Additionnal Audio Tracks : " << gNumAnalog << endl;

  cout << "* "
       << "Sample Rate : " << gSampleFactor * 22050 << endl;
  cout << "* "
       << "Buffer Processing Length : " << gBufferProLen << endl;
  float speed = ((gBufferProLen * 1.0f) / (gSampleFactor * 22050));
  cout << "* "
       << "Processing Speed (bufflen/samplerate) : " << speed << " s" << endl;
  if (gUseEffects) {
    cout << "* "
         << "Effects enabled (disable them for more speed)" << endl;
    cout << "       -> "
         << "Effect Buffer Size : " << gEffSize << endl;
  } else {
    cout << "* Effects disabled" << endl;
  }

  // Initialise auxiliary tasks
  if (((gFillBuffersTask =
            Bela_createAuxiliaryTask(&fillBuffers, 80, "fill-buffer")) == 0) ||
      ((gProcessBufferTask = Bela_createAuxiliaryTask(
            &processBuffer, 75, "process-buffer")) == 0) ||
      ((gEffectTask =
            Bela_createAuxiliaryTask(&processEffect, 85, "apply-effect")) == 0))
    // || ((gAdjustVolumeTask = Bela_createAuxiliaryTask(&processVolume, 90,
    // "adjust-volume")) == 0 ) )
    return false;
  return true;
}

struct timeval tv3;
struct timeval tv4;

int fillless = 0;
int fillcount = 10;

void render(BelaContext *context, void *userData) {
  // check if buffers need filling
  if (fillless == 0) {
    Bela_scheduleAuxiliaryTask(gFillBuffersTask);
  }
  fillless = (fillless + 1) % fillcount;

  /**** Main Loop ****/

  int contextanalogFrames =
      context->analogFrames; // analogue channels are the reference
  for (unsigned int n = 0; n < contextanalogFrames; n++) { // for each frame
    for (int i = 0; i < gNumStreams;
         i++) { // update pointers to next sample of file
      sampleStream[i]->processFrame();
      if (gSampleFactor == STANDARD_SAMPLE_RATE) { // if 22050 Hz
        sampleStream[i]->processFrame();
      }
    }

    /****** Correlations *******/

    float out = 0;
    if (gFillPosition == gBufferProLen - 1) {
      gProcessBufferCopy.swap(gProcessBuffer); // O(1)
      gFillPosition = -1;
      gBufferProcessed = 0;
      Bela_scheduleAuxiliaryTask(gProcessBufferTask);
    }

    /******* EFFECT LOOP ********/

    // POSSIBILITE DE FACTORISER LES BOUCLES AVEC OU SANS EFFET ?

    if (gUseEffects) { // uses additionnal buffers for effects

      // files
      for (int i = 0; i < gNumStreams; i++) {
        float sample =
            (sampleStream[i]->getSample(0) + sampleStream[i]->getSample(1)) / 2;
        gEffectBufferIn[i][gReadPointer] = sample;
      }

      // analog
      for (int r = 0; r < gNumAnalog; r++) {
        float sample = analogRead(context, n, r);
        gEffectBufferIn[gNumStreams + r][gReadPointer] = sample;
      }

      // audio
      for (int a = 0; a < gNumAudio; a++) {
        float sample;
        if (gSampleFactor == STANDARD_SAMPLE_RATE) { // if 22050 Hz
          sample = audioRead(context, 2 * n, a);
        } else {
          sample = audioRead(context, n, a);
        }
        gEffectBufferIn[gNumStreams + gNumAnalog + a][gReadPointer] = sample;
      }

      if (gReadPointer + 1 >= gEffSize) { // handle effect buffers
        gEffectBufferIn.swap(gEffectBufferInCopy);
        gIndIn = 0;
        gCopySize = gEffSize;
        gReadPointer = 0;
        if (gEffectStart == 1) {
          gIndOut = gEffSize;
          gWritePointer = 0;
        } else {
          gIndOut = (gLastSample + 1) % (2 * gEffSize);
        }
        Bela_scheduleAuxiliaryTask(gEffectTask);
      } else {
        gReadPointer++;
      }

      for (int s = 0; s < gNumStreams + gNumAnalog + gNumAudio;
           s++) { // transfert from Out to ProcessBuffer
        float outsample = gEffectBufferOut[s][gWritePointer];
        gProcessBuffer[s][gFillPosition + 1] = outsample;
        out += outsample;
      }
      gWritePointer = (gWritePointer + 1) % (2 * gEffSize);
      gFillPosition++;
    }

    /******* USUAL LOOP *******/

    else {

      // POSSIBILITE DE FACTORISER LES DIFFERENTES BOUCLES AUDIO ?

      // files
/*      for (int s = 0; s < gNumStreams; s++) {
        float outsample;
        outsample =
            (sampleStream[s]->getSample(0) + sampleStream[s]->getSample(1)) / 2;
        gProcessBuffer[s][gFillPosition + 1] = outsample;
        //audioWrite(context, n, s, outsample * gMeanCorrel[s]);
	    if (gSampleFactor == STANDARD_SAMPLE_RATE) {
	      audioWrite(context, 2 * n, 0, gMeanCorrel[s] * digitalRead(context, n, s));
	      audioWrite(context, 2 * n + 1, 0, gMeanCorrel[s] * digitalRead(context, n, s));
	    } else {
	      audioWrite(context, n, 0, gMeanCorrel[s] * digitalRead(context, n, s));
	    }
	    if (gSampleFactor == STANDARD_SAMPLE_RATE) {
	      audioWrite(context, 2 * n, 1, gMeanCorrel[s] * digitalRead(context, n, s));
	      audioWrite(context, 2 * n + 1, 1, gMeanCorrel[s] * digitalRead(context, n, s));
	    } else {
	      audioWrite(context, n, 1, gMeanCorrel[s] * digitalRead(context, n, s));
	    }
        out += outsample;
      } */
      
      float outsample;
      float out = 0.0f;
        outsample =
            (sampleStream[0]->getSample(0) + sampleStream[0]->getSample(1)) / 2;
        gProcessBuffer[0][gFillPosition + 1] = outsample;
        out += outsample*gMeanCorrel[0];
        outsample =
            (sampleStream[1]->getSample(0) + sampleStream[1]->getSample(1)) / 2;
        gProcessBuffer[1][gFillPosition + 1] = outsample;
        out += outsample*gMeanCorrel[1];
        outsample =
            (sampleStream[2]->getSample(0) + sampleStream[2]->getSample(1)) / 2;
        gProcessBuffer[2][gFillPosition + 1] = outsample;
        out += outsample*gMeanCorrel[2];
        audioWrite(context, n, 0, out);
        audioWrite(context, n, 1, out);

      // analog
      for (int r = 0; r < gNumAnalog; r++) {
        float outsample = analogRead(context, n, r);
        gProcessBuffer[gNumStreams + r][gFillPosition + 1] = outsample;
        //audioWrite(context, n, r, outsample * gMeanCorrel[gNumStreams + r]);
        out += outsample;
      }

      // audio
      for (int a = 0; a < gNumAudio; a++) {
        float outsample;
        if (gSampleFactor == STANDARD_SAMPLE_RATE) { // if 22050Hz
          outsample = audioRead(context, 2 * n, a);
          //audioWrite(context, n, a, outsample * gMeanCorrel[gNumStreams + gNumAnalog + a]);
        } else {
          outsample = audioRead(context, n, a);
          //audioWrite(context, n, a, outsample * gMeanCorrel[gNumStreams + gNumAnalog + a]);
        }
        gProcessBuffer[gNumStreams + gNumAnalog + a][gFillPosition + 1] =
            outsample;
        out += outsample;
      }
      gFillPosition++;
      out /= (gNumStreams + gNumAudio + gNumAnalog);
    }

    /******* WRITING IN AUDIO OUTPUT *******/

    // IS THIS LEFT AND RIGHT CHANNELS ?
    // IF YES PLEASE CHANGE FIRST/SECOND TO LEFT/RIGHT

    /* First Channel */

/*    if (gSampleFactor == STANDARD_SAMPLE_RATE) {
      audioWrite(context, 2 * n, 0, out);
      audioWrite(context, 2 * n + 1, 0, out);
    } else {
      audioWrite(context, n, 0, out);
    } */

    /* Second channel */

/*    if (gSampleFactor == STANDARD_SAMPLE_RATE) {
      audioWrite(context, 2 * n, 1, out);
      audioWrite(context, 2 * n + 1, 1, out);
    } else {
      audioWrite(context, n, 1, out);
    } */
  }
}

void cleanup(BelaContext *context, void *userData) {
  gUserSet.conn.end(); // end TCP connection
  for (int i = 0; i < gNumStreams; i++) {
    delete sampleStream[i];
  }
}
