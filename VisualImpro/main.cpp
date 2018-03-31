/***** main.cpp *****/

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

#include <Bela.h>
#include <cstdio>
#include <cstdlib>
#include <dlfcn.h>
#include <fcntl.h>
#include <getopt.h>
#include <iostream>
#include <libgen.h>
#include <list>
#include <signal.h>
#include <sndfile.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "ChannelsSettings.h"
#include "Echo.hpp"
#include "Parser.hpp"
#include "ProcessMultiCorrel.hpp"
#include "SampleData.h"
#include "utilities.hpp"
#include "Matrix.hpp"
#include "RGB.hpp"

using namespace std;

#define DLERROR(dlsymerror)                                                    \
  dlsymerror = dlerror();                                                      \
  if (dlsymerror) {                                                            \
    cout << "Error : " << dlsymerror << endl;                                  \
  }

//types which are used for processing functions
typedef RGB (*colorScale)(float coeff);
typedef float (*coeffCorrel)(const vector<float>& s1, const vector<float>& s2);
typedef Matrix<float> (*preProcess)(const Matrix<float>&);
typedef vector<float> (*mixLevel)(const Matrix<float>&);

// Global variables used by getCurrentTime()
static unsigned long long gFirstSeconds, gFirstMicroseconds;

/*** Function called by main program ***/

// Handle Ctrl-C by requesting that the audio rendering stop
static void interrupt_handler(int var) { gShouldStop = true; }

// Print usage information
static void usage(const char *processName) {
  cerr << "Usage: " << processName << " [options]" << endl;
  Bela_usage();
  cerr << "   --help [-h]:                Print this menu\n";
}

/* Function which returns the time since start of the program
 * in (fractional) seconds.
 */
static double getCurrentTime(void) {
  unsigned long long result;
  struct timeval tv;
  gettimeofday(&tv, NULL);
  result = (tv.tv_sec - gFirstSeconds) * 1000000ULL +
           (tv.tv_usec - gFirstMicroseconds);
  return (double)result / 1000000.0;
}


//Initialise the Parser by white the absolute path of the configuration file
static Parser initParser(int argc, char *argv[]){
  Parser config;
  if (argc <= 1){ // when the server is in the Bela
    config = Parser("/root/Bela/projects/VisualImpro/settings.cfg");
  } else { // when launched with VisualImproExe
    config = Parser(argv[1]);
  }
  return config;
}

//Initialise the handler with the absolute path of the dynamic library
static void* initHandler(){
  void *handle;
  handle = dlopen("/root/Bela/projects/VisualImpro/process/libprocess.so",
                        RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "dlopen failed: %s\n", dlerror());
    exit(EXIT_FAILURE);
  }
  return handle;
}

//Initialise the ProcessMultiCorrel object with default functions
static ProcessMultiCorrel* initProcessMultiCorrel(void* handle){
  //varible used to print the error
  char *dlsymerror;

  //Seek the defaut functions in the dynamic library
  coeffCorrel coeffFunc = (coeffCorrel)dlsym(handle, "CoeffScalar");
  DLERROR(dlsymerror);
  colorScale colorFunc = (colorScale)dlsym(handle, "ColorGreenToRed");
  DLERROR(dlsymerror);
  preProcess preprocFunc = (preProcess)dlsym(handle, "PreprocEnergy");
  DLERROR(dlsymerror);
  mixLevel mixFunc = (mixLevel)dlsym(handle, "MixMaxCorrelated");
  DLERROR(dlsymerror);

  return new ProcessMultiCorrel(coeffFunc, colorFunc, preprocFunc, mixFunc);
}

//Get the connexion parameter from the parser and set it in the structure
static void setupConnection(ChSettings& gChSettings, const Parser& config){
  Connection conn;
  int port = config.getPort();
  string ip = config.getAddress();
  if (port != 0 && ip != "") {
    conn = Connection(port, ip);
  }
  gChSettings.conn = conn;
}

/* Dynamic linking with libprocess.so to change the default functions of the
 * processing parameteters of the object ProcessMultiCorrel if needed
 */
static void parseProcessFunc(ChSettings& gChSettings, const Parser& config,
ProcessMultiCorrel *p, void *handle){
  //varible used to print the error
  char *dlsymerror;

  //Parse the configuration file to get the functions names and if there is one
  //then seek in the dynamic librery the function
  string configCoeff = config.getCoeff();
  if (configCoeff != "") {
    coeffCorrel coeffFunc = (coeffCorrel)dlsym(handle, configCoeff.c_str());
    DLERROR(dlsymerror);
    p->setCoeff(coeffFunc);
  }
  string configColor = config.getColor();
  if (configColor != "") {
    colorScale colorFunc = (colorScale)dlsym(handle, configColor.c_str());
    DLERROR(dlsymerror);
    p->setColor(colorFunc);
  }
  string configPreproc = config.getPreproc();
  if (configPreproc != "") {
    preProcess preprocFunc = (preProcess)dlsym(handle, configPreproc.c_str());
    DLERROR(dlsymerror);
    p->setPreproc(preprocFunc);
  }
  string configMix = config.getMix();
  if (configMix != "") {
    mixLevel mixFunc = (mixLevel)dlsym(handle, configMix.c_str());
    DLERROR(dlsymerror);
    p->setMix(mixFunc);
  }

  gChSettings.proc = p;
}

//Set the length values to the structure by parsing the configuration file
static void parseLengths(ChSettings& gChSettings, const Parser& config){
  int processlen = config.getProcessLength();
  int effectlen = config.getEffectLen();

  gChSettings.buffer_len = processlen;
  gChSettings.effect_len = effectlen;
}

//Set the track settings to the structure by parsing the configuration file
static void parseTracks(ChSettings& gChSettings, const Parser& config){
  list<string> files;
  files = config.getTracks();

  gChSettings.nb_audio = config.getAudio();
  gChSettings.nb_analog = config.getAnalog();

  //Check if the wevefiles are corrects and put them in the structure if so
  for (string file : files) {
    if (check_extension(file, "wav") && access(file.c_str(), F_OK) != -1) {
      gChSettings.filenames.push_back(file);
    } else {
      fprintf(stderr, "%s n'est pas un fichier wav existant, il n'a pas été chargé\n",
file.c_str());
    }
  }
  gChSettings.nb_files = gChSettings.filenames.size();

  //Check if there is at least one track
  if (gChSettings.nb_files + gChSettings.nb_analog + gChSettings.nb_audio == 0){
    fprintf(stderr, "No track, end");
    exit(EXIT_FAILURE);
  }

  //Check if the total number of tracks is not greater than the maximum number
  //tracks authorized
  if (gChSettings.nb_files + gChSettings.nb_analog + gChSettings.nb_audio >
      NB_TRACKS_MAX){
    fprintf(stderr, "Too many tracks");
    exit(EXIT_FAILURE);
  }
}

//Set the buffers in the structure with an effect for each instrument if we
//choose to enable effects
static void enableEffects(ChSettings& gChSettings, const Parser& config){
  if (config.getUseEffects() == true) {
    gChSettings.useeffects = true;
    for (int i = 0; i < gChSettings.nb_audio; i++) {
      gChSettings.audioproc.push_back(new Echo(44100, 0.5));
    }
    for (int i = 0; i < gChSettings.nb_analog; i++) {
      gChSettings.analogproc.push_back(new Echo(44100, 0.5));
    }
    for (int i = 0; i < gChSettings.nb_files; i++) {
      gChSettings.fileproc.push_back(new Echo(44100, 0.5));
    }
  } else {
    gChSettings.useeffects = false;
  }
}

//Set up everything relative to processing in our structure
static void setupProcess(ChSettings& gChSettings, const Parser& config,
ProcessMultiCorrel *p, void *handle){
  parseProcessFunc(gChSettings, config, p, handle);
  parseLengths(gChSettings, config);
  parseTracks(gChSettings, config);
  enableEffects(gChSettings, config);
}

//Initialise the first line of our log file
static void setupLogFile(const ChSettings& gChSettings){
  std::ofstream logfile;
  logfile.open("log/log");
  logfile << "BUFFERSIZE : " << gChSettings.buffer_len
          << " SAMPLE_RATE : " << gChSettings.sample_factor * 22050
          << std::endl;
  logfile.close();
}

//Set up every basic settings in our structure
static void setupSettings(ChSettings& gChSettings, const Parser& config,
ProcessMultiCorrel *p, void *handle){
  cout << "************* VisualImpro ************" << endl;
  setupConnection(gChSettings, config);
  setupProcess(gChSettings, config, p, handle);
  setupLogFile(gChSettings);
}

//Initialise the Bela settings with a BelaInitSettings object
static BelaInitSettings initBelaSettings(ChSettings& gChSettings, const Parser&
config, char* argv[]){
  // Standard audio settings
  BelaInitSettings settings;

  Bela_defaultSettings(&settings);

  struct option customOptions[] = {{"help", 0, NULL, 'h'}, {NULL, 0, NULL, 0}};

  // Set the settings manually, simulating a "false" argv command line
  vector<string> arguments;
  arguments.push_back("./VisualImpro");
  if (config.getAnalog() < 5) {
    arguments.push_back("-C");
    arguments.push_back("4");
    arguments.push_back("-Y");
    arguments.push_back("0,1,2,3");
    gChSettings.sample_factor = 2; // 44100 Hz
  } else {
    arguments.push_back("-C");
    arguments.push_back("8");
    arguments.push_back("-Y");
    arguments.push_back("0,1,2,3,4,5,6,7");
    gChSettings.sample_factor = 1; // 22050 Hz
  }

  vector<char *> argv2;
  for (const auto &arg : arguments)
    argv2.push_back((char *)arg.data());
  argv2.push_back(nullptr);

  // Parse the "false" argv command line
  while (1) {
    int c;
    if ((c = Bela_getopt_long(argv2.size() - 1, argv2.data(), "h",
                              customOptions, &settings)) < 0)
      break;
    switch (c) {
    case 'h':
      usage(basename(argv[0]));
      exit(0);
    case '?':
    default:
      usage(basename(argv[0]));
      exit(1);
    }
  }
  return settings;
}

//Initialise and start audio which is calling the setup function in render.cpp
static void initAndRun(ChSettings& gChSettings, const Parser& config,
char* argv[]){
  BelaInitSettings settings;
  struct timeval tv;

  //Initialise Bela settings
  settings = initBelaSettings(gChSettings, config, argv);

  // Initialise the PRU audio device
  if (Bela_initAudio(&settings, &gChSettings) != 0) {
    fprintf(stderr, "Error: unable to initialise audio\n");
    exit(EXIT_FAILURE);
  }

  // Initialise time
  gettimeofday(&tv, NULL);
  gFirstSeconds = tv.tv_sec;
  gFirstMicroseconds = tv.tv_usec;

  // Start the audio device running
  if (Bela_startAudio()) {
    fprintf(stderr, "Error: unable to start real-time audio\n");
    exit(EXIT_FAILURE);
  }

  // Set up interrupt handler to catch Ctrl-C signal or terminated program signal
  signal(SIGINT, interrupt_handler);
  signal(SIGTERM, interrupt_handler);

  // Run the program until it is told to stop
  while (!gShouldStop) {
    usleep(100000);
  }
}

//The program reveive a signal to stop the execution so we stop and clean audio
static void stopAndCleanupAudio(){
  // Stop the audio device
  Bela_stopAudio();

  // Clean up any resources allocated for audio
  Bela_cleanupAudio();
}

//We delete any ressources we used in the main.cpp file
static void freeAndClose(ChSettings& gChSettings, const Parser& config,
ProcessMultiCorrel *p, void *handle){
  // Free other resources
  if (config.getUseEffects() == true) {
    for (int i = 0; i < gChSettings.nb_audio; i++) {
      delete (gChSettings.audioproc[i]);
    }
    for (int i = 0; i < gChSettings.nb_analog; i++) {
      delete (gChSettings.analogproc[i]);
    }
    for (int i = 0; i < gChSettings.nb_files; i++) {
      delete (gChSettings.fileproc[i]);
    }
  }

  // close dlopen handle
  if(dlclose(handle) != 0){
    fprintf(stderr, "Error closing configuration file\n");
    exit(EXIT_FAILURE);
  }

  delete p;
}

//Declare and initialise variables then call every functions for the main program
static void launch(int argc, char *argv[]){
  ChSettings gChSettings;
  Parser config;
  void *handle;
  ProcessMultiCorrel *p;
  config = initParser(argc, argv);
  handle = initHandler();
  p = initProcessMultiCorrel(handle);
  setupSettings(gChSettings, config, p, handle);
  initAndRun(gChSettings, config, argv);
  stopAndCleanupAudio();
  freeAndClose(gChSettings, config, p, handle);
}

int main(int argc, char *argv[]) {
  launch(argc, argv);
  return 0;
}
