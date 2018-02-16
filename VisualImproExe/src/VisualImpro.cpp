#include "ExecParser.hpp"
#include "parse.hpp"

#include <iostream>
#include <list>
#include <signal.h>
#include <stdio.h>
#include <time.h>

using namespace std;

bool gShouldStop = false;

#define CONFIGFILE "./config.cfg"
#define CONFIGTMPFILE "./configtmp.cfg"

const std::string currentDateTime() {
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
  // for more information about date/time format
  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

  return buf;
}

void interrupt_handler(int var) {
  system("ssh root@192.168.7.2 pkill VisualImpro");
  system("pkill nodejs");
  string rmcmd =
      string("ssh root@192.168.7.2 rm ") + string(WAVPATH) + string("*.wav");
  system(rmcmd.c_str());

  string logfile = string("logs/") + currentDateTime();

  string logcmd = string("scp root@192.168.7.2:") + string(LOGPATH) +
                  string("log ") + logfile;
  system(logcmd.c_str());
  cout << "Data saved in " << logfile << endl;

  string rmconfig = string("rm ") + string(CONFIGTMPFILE);
  system(rmconfig.c_str());
  cout << endl << "Don't forget to close the web page" << endl;
  gShouldStop = true;
}

int main(int argc, char *argv[]) {

  signal(SIGINT, interrupt_handler);
  signal(SIGTERM, interrupt_handler);

  /*

-parser fichier config et copier tous les fichiers wav dans bela
-modifier fichier config pour avoir le bon répertoire pour les fichiers wav
(ex : FILE test.wav -> FILE /root/Bela/projects/VisualImpro/wavfiles/test.wav)
-copier fichier config dans bela (créer repertoire dédié)

-lancer serveur
-ouvrir page web firefox
-lancer VisualImpro

   */

  /*** Import Wav Files ****/

  ExecParser p(CONFIGFILE, CONFIGTMPFILE);
  list<string> files = p.getTracks();

  for (auto file : files) {
    string cmd = (string("scp ") + file + string(" root@192.168.7.2:") +
                  string(WAVPATH));
    cout << cmd << endl;
    system(cmd.c_str());
  }

  /**** Copy config file into Bela ***/

  string scpconfig = string("scp ") + string(CONFIGTMPFILE) +
                     string(" root@192.168.7.2:") + string(CONFIGPATH);
  cout << scpconfig << endl;
  system(scpconfig.c_str());

  /*** Launch Server ***/

  system("nodejs server.js &");
  sleep(5);
  system("firefox 192.168.7.1:8080 &");

  string execcmd =
      string("ssh root@192.168.7.2 ") +
      string("\'cd /root/Bela/projects/VisualImpro && ./VisualImpro config/") +
      string(CONFIGTMPFILE) + string("\' &");
  cout << execcmd << endl;
  system(execcmd.c_str());

  while (!gShouldStop) {
  }

  return 0;
}
