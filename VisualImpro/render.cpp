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
#include "Matrix.hpp"
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

Matrix<float>* gEffectBufferIn; // buffer filled in real time
Matrix<float>* gEffectBufferInCopy;
Matrix<float>* gEffectBufferOut;
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

void effect(Matrix<float> &In,
            Matrix<float> &Out) {
  assert(In.getSize() == gTotalTracks);
  int i;
  for (i = 0; i < gUserSet.nb_audio; i++) { // audio
    if (gUserSet.audioproc[i] == NULL) {
      In.getRowRef(i).swap(Out.getRowRef(i));
    } else {
      gUserSet.audioproc[i]->apply(In.getRowRef(i), Out.getRowRef(i));
    }
  }
  for (i = gUserSet.nb_audio; i < gUserSet.nb_audio + gUserSet.nb_analog;
       i++) { // analog
    if (gUserSet.analogproc[i - gUserSet.nb_audio] == NULL) {
      In.getRowRef(i).swap(Out.getRowRef(i));
    } else {
      gUserSet.analogproc[i - gUserSet.nb_audio]->apply(In.getRowRef(i), Out.getRowRef(i));
    }
  }
  for (i = gUserSet.nb_audio + gUserSet.nb_analog; i < gTotalTracks;
       i++) { // files
    if (gUserSet.fileproc[i - gUserSet.nb_audio - gUserSet.nb_analog] == NULL) {
      In.getRowRef(i).swap(Out.getRowRef(i));
    } else {
      gUserSet.fileproc[i - gUserSet.nb_audio - gUserSet.nb_analog]->apply(
          In.getRowRef(i), Out.getRowRef(i));
    }
  }
}

void processEffect() {
  genEffect(*gEffectBufferInCopy, gIndIn, *gEffectBufferOut, gIndOut, gCopySize,
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

/****** PROCESSING (MATRIX) TASKS AND VARS *******/

int gBufferProLen = 0;
int gNumStreams = NB_FILES_MAX;
int gNumAnalog = 0;
int gNumAudio = 0;
Matrix<float>* gProcessBuffer; // buffer filled in real time
Matrix<float>* gProcessBufferCopy; // buffer used to process

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
    p->process(*gProcessBufferCopy, gMeanCorrel, gUserSet.conn);
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

  gEffectBufferOut = new Matrix<float>(
      gTotalTracks, std::vector<float>(2 * gEffSize, 0.0f));
  gEffectBufferIn = new Matrix<float>(
      gTotalTracks, std::vector<float>(gEffSize, 0.0f));
  gEffectBufferInCopy = new Matrix<float>(
      gTotalTracks, std::vector<float>(gEffSize, 0.0f));

  // Initialize process buffers

  gProcessBuffer = new Matrix<float>(
      gTotalTracks, std::vector<float>(gUserSet.buffer_len, 0.0f));
  gProcessBufferCopy = new Matrix<float>(
      gTotalTracks, std::vector<float>(gUserSet.buffer_len, 0.0f));

  for (int i = 0; i < gNumStreams; i++) {
    int nbchan = getChannelNumber(gUserSet.filenames[i]);
    sampleStream[i] = new SampleStream(gUserSet.filenames[i].c_str(), nbchan,
                                       FILE_BUFFER_LEN);
  }

  for (int i = 0; i < gUserSet.nb_files; i++) {
    sampleStream[i]->togglePlayback(1);
  }

  // Initialize mix Buffer

  std::vector<float> mixbuffer(gTotalTracks, 1.0f);
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

  // analog channels are the reference
  for (unsigned int n = 0; n < context->analogFrames; n++) { // for each frame
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
      gProcessBufferCopy->swap(*gProcessBuffer); // O(1)
      gFillPosition = -1;
      gBufferProcessed = 0;
      Bela_scheduleAuxiliaryTask(gProcessBufferTask);
    }

    /******* EFFECT LOOP ********/

    if (gUseEffects) { // uses additionnal buffers for effects

      // files
      for (int i = 0; i < gNumStreams; i++) {
        float sample =
            (sampleStream[i]->getSample(0) + sampleStream[i]->getSample(1)) / 2;
        gEffectBufferIn->setCase(i, gReadPointer, sample);
      }

      // analog
      for (int r = 0; r < gNumAnalog; r++) {
        float sample = analogRead(context, n, r);
        gEffectBufferIn->setCase(gNumStreams + r, gReadPointer, sample);
      }

      // audio
      for (int a = 0; a < gNumAudio; a++) {
        float sample;
        if (gSampleFactor == STANDARD_SAMPLE_RATE) { // if 22050 Hz
          sample = audioRead(context, 2 * n, a);
        } else {
          sample = audioRead(context, n, a);
        }
        gEffectBufferIn->setCase(gNumStreams + gNumAnalog + a, gReadPointer, sample);
      }

      if (gReadPointer + 1 >= gEffSize) { // handle effect buffers
        gEffectBufferIn->swap(*gEffectBufferInCopy);
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
        float outsample = gEffectBufferOut->getCase(s, gWritePointer);
        gProcessBuffer->setCase(s, gFillPosition + 1, outsample);
        out += outsample;
      }
      gWritePointer = (gWritePointer + 1) % (2 * gEffSize);
      gFillPosition++;
    }

    /******* USUAL LOOP *******/

    else {

      float outsample;
      for (int s = 0; s < gNumStreams; s++) {
        outsample = (sampleStream[s]->getSample(0) + sampleStream[s]->getSample(1)) / 2;
        gProcessBuffer->setCase(s, gFillPosition + 1, outsample);
        out += outsample*gMeanCorrel[s];
	  }

      // analog
      for (int r = 0; r < gNumAnalog; r++) {
        float outsample = analogRead(context, n, r);
        gProcessBuffer->setCase(gNumStreams + r, gFillPosition + 1, outsample);
        out += outsample;
      }

      // audio
      for (int a = 0; a < gNumAudio; a++) {
        if (gSampleFactor == STANDARD_SAMPLE_RATE) { // if 22050Hz
          outsample = audioRead(context, 2 * n, a);
        } else {
          outsample = audioRead(context, n, a);
        }
        gProcessBuffer->setCase(gNumStreams + gNumAnalog + a, gFillPosition + 1, outsample);
        out += outsample;
      }
      gFillPosition++;
      out /= (gNumStreams + gNumAudio + gNumAnalog);
    }

    /******* WRITING IN AUDIO OUTPUT *******/

    for(unsigned int i=0; i<context->audioOutChannels; i++){
  	    if (gSampleFactor == STANDARD_SAMPLE_RATE) {
          audioWrite(context, 2 * n, i, out);
  	      audioWrite(context, 2 * n + 1, i, out);
  	    } else {
  	      audioWrite(context, n, i, out);
  	    }
  	}
  }
}

void cleanup(BelaContext *context, void *userData) {
  gUserSet.conn.end(); // end TCP connection
  for (int i = 0; i < gNumStreams; i++) {
    delete sampleStream[i];
  }
}
