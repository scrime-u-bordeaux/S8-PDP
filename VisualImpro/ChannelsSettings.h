/**
 *  @file    ChannelsSettings.h
 *  @author  Jérémy LIXANDRE
 *  @date    July 2017
 *
 *  @section DESCRIPTION
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

#define STANDARD_SAMPLE_RATE 1 // Sample rates are multiples of this
#define DOUBLE_SAMPLE_RATE 2

#define FILE_BUFFER_LEN 44100

using namespace std;

typedef void (*process)(float**, float**);

struct ChSettings{

bool useeffects; //if effects are activated (much faster if disabled)

int nb_audio; //number of audio channels
int nb_analog; //number of analog channels
int nb_files; //number of files to play

vector<Effect*> audioproc; //effects for each audio track
vector<Effect*> analogproc; //idem for analogue
vector<Effect*> fileproc; //idem for files

vector<string> filenames;

int buffer_len; //length of buffers to process
int effect_len; //length of buffer for effects (the smaller the better)

int sample_factor; //1 (22050) or 2 (44100)

ProcessMultiCorrel * proc; //process to use (polymorphisme)


Connection conn; //connection to server

};

#endif // CHANNELSSETTINGS_H
