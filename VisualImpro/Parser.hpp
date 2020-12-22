#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <iostream>
#include <list>
#include "ChannelsSettings.h"
#include "parse.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class Parser
 * \brief Class used to parse a configuration file
 *
 * This class will parse the file containing the settings and will store in its
 * class members variables every settings relative to this file.
 */
class Parser{

public :
  Parser(string file);
  Parser(){}
  ~Parser(){}
  string getCoeff() const;
  string getColor() const;
  string getPreproc() const;
  string getMix() const;
  string getAddress() const;
  int getAnalog() const;
  int getAudio() const;
  int getPort() const;
  int getProcessLength() const;
  int getUseEffects() const;
  int getEffectLen() const;
  string getSessionName() const;
  list<string> getTracks() const;

private :
  string _file;
  list<string> tracks;
  string coeff;
  string color;
  string preproc;
  string mix;
  string sessionName;
  int port;
  int analog;
  int audio;
  bool useeffects;
  int efflen; //length of effect buffer
  string addr; //IP ADDRESS
  int proclen; //length of processing buffer
  static string get_word(string line);

};

#endif //PARSER_HPP
