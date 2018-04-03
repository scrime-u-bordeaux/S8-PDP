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

#include <cmath>
#include <vector>
#include <Bela.h>
#include <sys/time.h>
#include <time.h>
#include <SampleStream.hpp>
#include "ChannelsSettings.h"
#include "Echo.hpp"
#include "EffectManaging.hpp"
#include "Matrix.hpp"
#include "ProcessMultiCorrel.hpp"
#include "ProcessMultiWriteWav.hpp"
#include "utilities.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/******* GENERAL SETTINGS *******/

/**
 * \var gUserSet      Structure containing the user settings
 * \var gTotalTracks  Number of tracks
 * \var gSampleFactor Sampling at 22050 Hz
 */
ChSettings gUserSet;
int gTotalTracks = 0;
int gSampleFactor = 1;

SampleStream *sampleStream[NB_FILES_MAX];
AuxiliaryTask gFillBuffersTask;

/******* EFFECTS VARIABLES AND TASKS *******/

/**
 * \var gEffectBufferIn      Buffer filled in real time
 * \var gEffectBufferInCopy  Buffer sent as the In effect buffer
 * \var gEffectBufferOut     Buffer storing the effects signals results
 */
Matrix<float>* gEffectBufferIn;
Matrix<float>* gEffectBufferInCopy;
Matrix<float>* gEffectBufferOut;

bool gUseEffects = false;
int gEffSize = 0;
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

/**
 * \fn     void effect(Matrix<float> &In, Matrix<float> &Out)
 * \brief  Applies an effect from buffer In to buffer Out.
 *
 * \param  In  The matrix containing the signal pre effect
 * \param  Out The matrix containing the signal post effect
 */
void effect(Matrix<float> &In, Matrix<float> &Out){
  assert(In.getSize() == gTotalTracks);

  // Audio
  for (int i = 0; i < gUserSet.nb_audio; i++) { // audio
    if (gUserSet.audioproc[i] == NULL) {
      In.getRowRef(i).swap(Out.getRowRef(i));
    } else {
      gUserSet.audioproc[i]->apply(In.getRowRef(i), Out.getRowRef(i));
    }
  }

  // Analog
  for (int i = gUserSet.nb_audio; i < gUserSet.nb_audio + gUserSet.nb_analog;
      i++) {
    if (gUserSet.analogproc[i - gUserSet.nb_audio] == NULL) {
      In.getRowRef(i).swap(Out.getRowRef(i));
    } else {
      gUserSet.analogproc[i - gUserSet.nb_audio]->apply(In.getRowRef(i),
                                                        Out.getRowRef(i));
    }
  }

  // Files
  for (int i = gUserSet.nb_audio + gUserSet.nb_analog; i < gTotalTracks;
       i++) {
    if (gUserSet.fileproc[i - gUserSet.nb_audio - gUserSet.nb_analog] == NULL) {
      In.getRowRef(i).swap(Out.getRowRef(i));
    } else {
      gUserSet.fileproc[i - gUserSet.nb_audio - gUserSet.nb_analog]->apply(
          In.getRowRef(i), Out.getRowRef(i));
    }
  }
}

/**
 * \fn     void processEffect()
 * \brief  Auxiliary task used to call the effect function and update effect
 *         parameters.
 */
void processEffect() {
  // This function is located in EffectManaging.hpp
  genEffect(*gEffectBufferInCopy, gIndIn, *gEffectBufferOut, gIndOut, gCopySize,
            2 * gEffSize, effect);
  gEffectProcessing = 0;
  if (gEffectStart == 1) {
    gLastSample = 2 * gEffSize - 1;
    gEffectStart = 0;
  } else {
    gLastSample = (gLastSample + gCopySize) % (2 * gEffSize);
  }
}

/****** PROCESSING VARIABLES AND TASKS *******/

int gBufferProLen = 0;
int gNumStreams = NB_FILES_MAX;
int gNumAnalog = 0;
int gNumAudio = 0;

/**
 * \var gProcessBuffer      Buffer filled in real time
 * \var gProcessBufferCopy  Buffer used to process signals
 * \var gMeanCorrel         Buffer used to process volumes
 */
Matrix<float>* gProcessBuffer;
Matrix<float>* gProcessBufferCopy;
vector<float> gMeanCorrel;

/**
 * \var gFillPosition Last position that was filled. When
 *                    gFillPosition = BUFFERLEN-1, buffer should be analyzed
 *                    and empty'd
 */
int gFillPosition = -1;

AuxiliaryTask gProcessBufferTask;
bool gBufferProcessed = 1;

ProcessMultiCorrel *p;

struct timeval tv;
struct timeval tv2;
struct timeval tv3;
struct timeval tv4;

int fillless = 0;
int fillcount = 10;

/**
 * \fn     void fillBuffers()
 * \brief  Auxiliary Ttsk for filling sample buffers.
 */
void fillBuffers() {
  for (int i = 0; i < gUserSet.nb_files; i++) {
    if (sampleStream[i]->bufferNeedsFilled())
      sampleStream[i]->fillBuffer();
  }
}

/**
 * \fn     void processBuffer()
 * \brief  Auxiliary task for processing with the ProcessMultiCorrel functions.
 */
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

/**
 * \fn     void initUserSet(ChSettings& gUserSet)
 * \brief  Initialize the global variables with the values contained in the
 *         userData structure sent from main.cpp.
 *
 * \param  gUserSet The channel settings structure.
 */
void initUserSet(ChSettings& gUserSet){
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
}

/**
 * \fn     void initBuffers()
 * \brief  Initialize the effect, process and mix bufferss.
 */
void initBuffers(){
  // Initialize effect buffers
  gEffectBufferOut = new Matrix<float>(
      gTotalTracks, vector<float>(2 * gEffSize, 0.0f));
  gEffectBufferIn = new Matrix<float>(
      gTotalTracks, vector<float>(gEffSize, 0.0f));
  gEffectBufferInCopy = new Matrix<float>(
      gTotalTracks, vector<float>(gEffSize, 0.0f));

  // Initialize process buffers
  gProcessBuffer = new Matrix<float>(
      gTotalTracks, vector<float>(gBufferProLen, 0.0f));
  gProcessBufferCopy = new Matrix<float>(
      gTotalTracks, vector<float>(gBufferProLen, 0.0f));

  // Initialize mix Buffer
  vector<float> mixbuffer(gTotalTracks, 1.0f);
  gMeanCorrel = mixbuffer;

}

/**
 * \fn     void initSampleStreams(const ChSettings& gUserSet)
 * \brief  Initialize the SampleStream array with the wavefiles contained in
 *         the structure sent from main.cpp and set them as playable.
 *
 * \param  gUserSet The channel settings structure.
 */
void initSampleStreams(const ChSettings& gUserSet){
  for (int i = 0; i < gNumStreams; i++) {
    int nbchan = getChannelNumber(gUserSet.filenames[i]);
    sampleStream[i] = new SampleStream(gUserSet.filenames[i].c_str(), nbchan,
                                       FILE_BUFFER_LEN);
  }
  for (int i = 0; i < gUserSet.nb_files; i++) {
    sampleStream[i]->togglePlayback(1);
  }
}

/**
 * \fn     void printInfo()
 * \brief  Print on the standard output the information about the program.
 */
void printInfo(){
  cout << endl << endl;
  cout << "------ Settings ------" << endl;
  cout << "* " << "Files : " << gNumStreams << endl;
  cout << "* " << "Standard Audio Tracks : " << gNumAudio << endl;
  cout << "* " << "Additionnal Audio Tracks : " << gNumAnalog << endl;
  cout << "* " << "Sample Rate : " << gSampleFactor * 22050 << endl;
  cout << "* " << "Buffer Processing Length : " << gBufferProLen << endl;
  float speed = ((gBufferProLen * 1.0f) / (gSampleFactor * 22050));
  cout << "* " << "Processing Speed (bufflen/samplerate) : " << speed;
  cout <<" s" << endl;
  if (gUseEffects) {
    cout << "* " << "Effects enabled (disable them for more speed)" << endl;
    cout << "       -> " << "Effect Buffer Size : " << gEffSize << endl;
  } else {
    cout << "* Effects disabled" << endl;
  }
}

/**
 * \fn     bool initAuxiliaryTasks()
 * \brief  Initalise every auxiliary task.
 *
 * \return true if all the auxiliary tasks were initialized succefully,
 *         false if not.
 */
bool initAuxiliaryTasks(){
  if (((gFillBuffersTask =
            Bela_createAuxiliaryTask(&fillBuffers, 80, "fill-buffer")) == 0) ||
      ((gProcessBufferTask = Bela_createAuxiliaryTask(
            &processBuffer, 75, "process-buffer")) == 0) ||
      ((gEffectTask =
            Bela_createAuxiliaryTask(&processEffect, 85, "apply-effect")) == 0))
    return false;
  return true;
}

/**
 * \fn     bool setup(BelaContext *context, void *userData)
 * \brief  Set up ressources and parameters.
 *
 * \param  context  The bela default settings
 * \param  userData The parameters given by the user.
 * \return true if all the auxiliary tasks were initialized succefully,
 *         false if not.
 *
 * One of the three primary bela functions used in this file
 * setup is used to Initialize ressources and set up parameters.
 */
bool setup(BelaContext *context, void *userData) {
  gUserSet = *((ChSettings *)userData);
  initUserSet(gUserSet);
  initBuffers();
  initSampleStreams(gUserSet);
  printInfo();
  return initAuxiliaryTasks();
}

/**
 * \fn     void render(BelaContext *context, void *userData)
 * \brief  Process loop for writing audio and schedule auxiliary tasks.
 *
 * \param  context  The bela default settings
 * \param  userData The parameters given by the user.
 *
 * The second primary Bela function used in this file.
 * The render function is called recursively until it is told to stop by a
 * signal. We use this function to launch auxiliary task, executed by other
 * threads, and write the audio frames in the audio standar output.
 */
void render(BelaContext *context, void *userData) {

  // Check if buffers need filling
  if (fillless == 0) {
    Bela_scheduleAuxiliaryTask(gFillBuffersTask);
  }
  fillless = (fillless + 1) % fillcount;

  /**** Main Loop ****/

  // Analog channels are the reference
  for (unsigned int n = 0; n < context->analogFrames; n++) { // for each frame

    // Update sampleStream with the actual frame values
    for (int i = 0; i < gNumStreams; i++) {
      sampleStream[i]->processFrame();
      if (gSampleFactor == STANDARD_SAMPLE_RATE) { // if 22050 Hz
        sampleStream[i]->processFrame();
      }
    }

    // Variables used to store audio signals from the frame
    float out = 0;
    float insample = 0;
    float outsample = 0;

    /****** Correlations *******/

    if (gFillPosition == gBufferProLen - 1) {
      gProcessBufferCopy->swap(*gProcessBuffer); // O(1)
      gFillPosition = -1;
      gBufferProcessed = 0;
      Bela_scheduleAuxiliaryTask(gProcessBufferTask);
    }

    /******* EFFECT LOOP ********/

    if (gUseEffects) {
      // Files
      for (int i = 0; i < gNumStreams; i++) {
        insample =
            (sampleStream[i]->getSample(0) + sampleStream[i]->getSample(1)) / 2;
        gEffectBufferIn->setCase(i, gReadPointer, insample);
      }

      // Analog
      for (int r = 0; r < gNumAnalog; r++) {
        insample = analogRead(context, n, r);
        gEffectBufferIn->setCase(gNumStreams + r, gReadPointer, insample);
      }

      // Audio
      for (int a = 0; a < gNumAudio; a++) {
        if (gSampleFactor == STANDARD_SAMPLE_RATE) { // if 22050 Hz
          insample = audioRead(context, 2 * n, a);
        } else {
          insample = audioRead(context, n, a);
        }
        gEffectBufferIn->setCase(gNumStreams + gNumAnalog + a, gReadPointer,
                                insample);
      }

      // If geffectBufferIn is full,
      // then update effect parameters and launch the effect auxiliary task
      if (gReadPointer + 1 >= gEffSize) {
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

      // Transfert informations from the effect buffer Out to the process buffer
      for (int s = 0; s < gNumStreams + gNumAnalog + gNumAudio; s++) {
        float outsample = gEffectBufferOut->getCase(s, gWritePointer);
        gProcessBuffer->setCase(s, gFillPosition + 1, outsample);
        out += outsample;
      }
      gWritePointer = (gWritePointer + 1) % (2 * gEffSize);
      gFillPosition++;
    }

    /******* USUAL LOOP *******/

    else {
      // Files
      for (int s = 0; s < gNumStreams; s++) {
        outsample = (sampleStream[s]->getSample(0) +
                     sampleStream[s]->getSample(1)) / 2;
        gProcessBuffer->setCase(s, gFillPosition + 1, outsample);
        out += outsample*gMeanCorrel[s];
	     }

      // Analog
      for (int r = 0; r < gNumAnalog; r++) {
        float outsample = analogRead(context, n, r);
        gProcessBuffer->setCase(gNumStreams + r, gFillPosition + 1, outsample);
        out += outsample;
      }

      // Audio
      for (int a = 0; a < gNumAudio; a++) {
        if (gSampleFactor == STANDARD_SAMPLE_RATE) { // if 22050Hz
          outsample = audioRead(context, 2 * n, a);
        } else {
          outsample = audioRead(context, n, a);
        }
        gProcessBuffer->setCase(gNumStreams + gNumAnalog + a, gFillPosition + 1,
                                outsample);
        out += outsample;
      }
    }

    gFillPosition++;
    out /= (gNumStreams + gNumAudio + gNumAnalog);

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

/**
 * \fn     void cleanup(BelaContext *context, void *userData)
 * \brief  Clean the ressources and close connection
 *
 * \param  context  The bela default settings
 * \param  userData The parameters given by the user.
 *
 * Last one of the three primary Bela function used in this file
 * cleanup is used to free ressources as closing the connection and deleting
 * every samples stored in the sampleStrem array
 */
void cleanup(BelaContext *context, void *userData) {
  gUserSet.conn.end(); // end UDP connection
  for (int i = 0; i < gNumStreams; i++) {
    delete sampleStream[i];
  }
}
