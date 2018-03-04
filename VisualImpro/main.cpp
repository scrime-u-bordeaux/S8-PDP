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

#include "ChannelsSettings.h"
#include "Echo.hpp"
#include "Parser.hpp"
#include "ProcessMultiCorrel.hpp"
#include "SampleData.h"
#include "utilities.hpp"
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
#include <sndfile.h> // to load audio files
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

// Global variables used by getCurrentTime()
unsigned long long gFirstSeconds, gFirstMicroseconds;

// Handle Ctrl-C by requesting that the audio rendering stop
void interrupt_handler(int var) { gShouldStop = true; }

// Print usage information
void usage(const char *processName) {
  cerr << "Usage: " << processName << " [options]" << endl;

  Bela_usage();

  cerr << "   --help [-h]:                Print this menu\n";
}

/* Function which returns the time since start of the program
 * in (fractional) seconds.
 */
double getCurrentTime(void) {
  unsigned long long result;
  struct timeval tv;

  gettimeofday(&tv, NULL);
  result = (tv.tv_sec - gFirstSeconds) * 1000000ULL +
           (tv.tv_usec - gFirstMicroseconds);
  return (double)result / 1000000.0;
}

#define DLERROR(dlsymerror)                                                    \
  dlsymerror = dlerror();                                                      \
  if (dlsymerror) {                                                            \
    cout << "Error : " << dlsymerror << endl;                                  \
  }

typedef Triplet (*colorScale)(float coeff);
typedef float (*coeffCorrel)(vector<float> s1, vector<float> s2);
typedef vector<vector<float> > (*preProcess)(vector<vector<float> >);
typedef vector<float> (*mixLevel)(vector<vector<float> >);

int main(int argc, char *argv[]) {

  cout << "************* VisualImpro ************" << endl;

  /****** Default Settings and Variables Declaration ********/

  ChSettings gChSettings;

  string dlcolor = "ColorGreenToRed";
  string dlcoeff = "CoeffScalar";
  string dlpreproc = "PreprocEnergy";
  string dlmix = "MixMaxCorrelated";
  list<string> files;
  Connection conn;

  Parser config;

  if (argc <= 1) // when the server is in the Bela
  {
    config = Parser("/root/Bela/projects/VisualImpro/settings.cfg");
  } else { // when launched with VisualImproExe
    config = Parser(argv[1]);
  }

  /***** Connection *****/

  int port = config.getPort();
  string ip = config.getAddress();
  if (port != 0 && ip != "") {
    conn = Connection(port, ip);
  }
  gChSettings.conn = conn;

  /***** Dynamic Linking with libprocess.so ******/

  string configcolor = config.getColor();
  if (configcolor != "") {
    dlcolor = configcolor;
  }
  string configcoeff = config.getCoeff();
  if (configcoeff != "") {
    dlcoeff = configcoeff;
  }
  string configpreproc = config.getPreproc();
  if (configpreproc != "") {
    dlpreproc = configpreproc;
  }
  string configmix = config.getMix();
  if (configmix != "") {
    dlmix = configmix;
  }

  // lib must be optimized at its best

  /* Calling Library */
  void *handle = dlopen("/root/Bela/projects/VisualImpro/process/libprocess.so",
                        RTLD_LAZY);
  if (handle == NULL) {
    cout << "error lib" << endl;
    return -1;
  }

  char *dlsymerror;

  colorScale color1 = (colorScale)dlsym(handle, dlcolor.c_str());
  DLERROR(dlsymerror);
  preProcess preproc1 = (preProcess)dlsym(handle, dlpreproc.c_str());
  DLERROR(dlsymerror);
  coeffCorrel coeff1 = (coeffCorrel)dlsym(handle, dlcoeff.c_str());
  DLERROR(dlsymerror);
  mixLevel mix1 = (mixLevel)dlsym(handle, dlmix.c_str());
  DLERROR(dlsymerror);

  /***** Tracks Settings ******/

  files = config.getTracks();

  gChSettings.nb_audio = config.getAudio();
  gChSettings.nb_analog = config.getAnalog();

  for (string file : files) {
    if (check_extension(file, "wav") && access(file.c_str(), F_OK) != -1) {
      gChSettings.filenames.push_back(file);
    } else {
      cout << file
           << " n'est pas un fichier wav existant, il n'a pas été chargé"
           << endl;
    }
  }
  gChSettings.nb_files = gChSettings.filenames.size();

  if (gChSettings.nb_files + gChSettings.nb_analog + gChSettings.nb_audio ==
      0) {
    cout << "No track, end" << endl;
    return -1;
  }

  if (gChSettings.nb_files + gChSettings.nb_analog + gChSettings.nb_audio >
      NB_TRACKS_MAX) {
    cout << "Too many tracks" << endl;
    return -1;
  }

  /***** Processing and Effects Settings *****/

  int processlen = config.getProcessLength();
  int effectlen = config.getEffectLen();

  gChSettings.buffer_len = processlen;
  gChSettings.effect_len = effectlen;

  /* Choose process */

  ProcessMultiCorrel *p = new ProcessMultiCorrel(coeff1, color1, preproc1, mix1);
  gChSettings.proc = p;

  /****** Enable effects ? ******/

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

  /******** Bela Settings ********/

  BelaInitSettings settings; // Standard audio settings
  struct timeval tv;

  Bela_defaultSettings(&settings);

  struct option customOptions[] = {{"help", 0, NULL, 'h'}, {NULL, 0, NULL, 0}};

  // Set settings manually, simulating a "false" command line argv
  vector<string> arguments;
  arguments.push_back("./VisualImpro");
  if (config.getAnalog() < 5) {
    arguments.push_back("-C");
    arguments.push_back("4");
    arguments.push_back("-Y");
    arguments.push_back("0,1,2,3");
    gChSettings.sample_factor = 2; // 22050 Hz
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

  // Parse the false command line
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

  /******** Init log file ********/

  std::ofstream logfile;
  logfile.open("log/log");
  logfile << "BUFFERSIZE : " << gChSettings.buffer_len
          << " SAMPLE_RATE : " << gChSettings.sample_factor * 22050
          << std::endl;
  logfile.close();

  // Initialise the PRU audio device

  if (Bela_initAudio(&settings, &gChSettings) != 0) {
    cout << "Error: unable to initialise audio" << endl;
    return -1;
  }

  // Initialise time
  gettimeofday(&tv, NULL);
  gFirstSeconds = tv.tv_sec;
  gFirstMicroseconds = tv.tv_usec;

  // Start the audio device running
  if (Bela_startAudio()) {
    cout << "Error: unable to start real-time audio" << endl;
    return -1;
  }

  // Set up interrupt handler to catch Control-C
  signal(SIGINT, interrupt_handler);
  signal(SIGTERM, interrupt_handler);

  // Run until told to stop
  while (!gShouldStop) {
    usleep(100000);
  }

  // Stop the audio device
  Bela_stopAudio();

  // Clean up any resources allocated for audio
  Bela_cleanupAudio();

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

  delete p;

  // close dlopen handle
  dlclose(handle);

  // All done!
  return 0;
}
