/**
 *  \file    ChannelsSettings.h
 *  \author  Jérémy LIXANDRE
 *  \date    July 2017
 *
 *  \brief File containing the structure ChSettings.
 *
 *  The ChannelsSettings structure is declared and filled in main.cpp, and
 *  contains the parameters given to the program, such as the number of tracks
 *  of each type, the processing functions, and the processing buffers lengths.
 *
 */

#ifndef CHANNELSSETTINGS_H
#define CHANNELSSETTINGS_H

#include <string>
#include <vector>
#include "Connection.hpp"
#include "Effect.hpp"
#include "ProcessMultiCorrel.hpp"

#define NB_AUDIO_MAX 2
#define NB_ANALOG_MAX 8

#define NB_FILES_MAX 20
#define NB_TRACKS_MAX 20

#define DEFAULT_PROCESS_LEN 32768
#define DEFAULT_EFFECT_LEN 32

#define STANDARD_SAMPLE_RATE 1
#define DOUBLE_SAMPLE_RATE 2

#define FILE_BUFFER_LEN 44100

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

typedef void (*process)(float**, float**);

/**
 *  \struct ChSettings
 *  \brief Object containing the settings given by the user
 */
struct ChSettings{
  /**
   * \var useeffects If effects are activated (much faster if disabled)
   */
  bool useeffects;

  /**
   * \var nb_audio  Number of audio channels
   * \var nb_analog Number of analog channels
   * \var nb_files  Number of files to play
   */
  int nb_audio;
  int nb_analog;
  int nb_files;

  /**
   * \var audioproc  Effects for each audio track
   * \var analogproc Idem for analogue
   * \var fileproc   Idem for files
   */
  vector<Effect*> audioproc;
  vector<Effect*> analogproc;
  vector<Effect*> fileproc;

  /**
   * \var filenames All the filenames of the tracks in this vector
   */
  vector<string> filenames;

  /**
   * \var buffer_len Length of buffers to process
   * \var effect_len Length of buffer for effects (the smaller the better)
   */
  int buffer_len;
  int effect_len;

  /**
   * \var sample_factor Values are : 1 (22050) or 2 (44100)
   */
  int sample_factor;

  /**
   * \var proc Process to use (polymorphisme)
   */
   
  ProcessMultiCorrel * proc;

  /**
   * \var conn Connection to server
   */
  Connection conn;

};

#endif // CHANNELSSETTINGS_H
