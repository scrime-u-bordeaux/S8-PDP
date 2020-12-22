// TODO: seek/rewind functions

#ifndef SAMPLESTREAM_HPP
#define SAMPLESTREAM_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <Bela.h>
#include <SampleData.h>
#include <libraries/sndfile/sndfile.h>	// to load audio files

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class SampleStream
 * \brief Class used to contain wavefiles.
 *
 * This class will contain the wavefiles used in the program. A SampleStream
 * array is declared in render.cpp and is representing our wavefiles.
 */
class SampleStream{
  public:
    SampleStream(const char* filename, int numChannels, int bufferLength);
    ~SampleStream();
    int openFile(const char* filename, int numChannels, int bufferLength);
    void fillBuffer();
    void processFrame();
    float getSample(int channel);
    int bufferNeedsFilled();
    void togglePlayback();
    void togglePlaybackWithFade(float fadeLengthInSeconds);
    void togglePlayback(int toggle);
    void togglePlaybackWithFade(int toggle, float fadeLengthInSeconds);
    int isPlaying();

  private:
    // private libsndfile wrappers
    int getSamples(const char* file, float *buf, int channel, int startFrame,\
    int endFrame);

    int getNumChannels(const char* file);
    int getNumFrames(const char* file);

    /**
     * \var gSampleBuf Two buffers for each channel : one of them loads the next
     *                 chunk of audio while the other one is used for playback.
     */
    SampleData *gSampleBuf[2];

    /**
     * \var gReadPtr read pointer relative current buffer (range 0-BUFFER_LEN),
     *               initialized at BUFFER_LEN to pre-load second buffer
     *               (see render())
     */
    int gReadPtr;

    /**
     * \var gBufferReadPtr read pointer relative to file, increments by
     *                     BUFFER_LEN (see fillBuffer())
     */
    int gBufferReadPtr;

    /**
     * \var gBufferReadPtr keeps track of which buffer is currently active
     *                     (switches between 0 and 1)
     */
    int gActiveBuffer;

    /**
     * \var gDoneLoadingBuffer this variable will let us know if the buffer
     *                         doesn't manage to load in time
     */
    int gDoneLoadingBuffer;
    int gBufferLength;
    int gNumChannels;

    int gNumFramesInFile;
    const char* gFilename;
    int gBufferToBeFilled;
    int gPlaying;

    float gFadeAmount;
    float gFadeLengthInSeconds;
    int gFadeDirection;

    int gBusy;

    SNDFILE *sndfile ;
	  SF_INFO sfinfo ;

};

#endif // SAMPLESTREAM_HPP
