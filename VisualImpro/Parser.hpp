#ifndef PARSER_HPP
#define PARSER_HPP

#include "parse.hpp"
#include "ChannelsSettings.h"
#include <list>
#include <iostream>
#include <fstream>

class Parser{

public :
  Parser(std::string file);
  Parser(){}
  ~Parser(){}
  std::string getCoeff();
  std::string getColor();
  std::string getPreproc();
  std::string getMix();
  std::string getAddress();
  int getAnalog();
  int getAudio();
  int getPort();
  int getProcessLength();
  int getUseEffects();
  int getEffectLen();
  std::string getSessionName();
  std::list<std::string> getTracks();
  
private :
  std::string _file;
  std::list<std::string> tracks;
  std::string coeff;
  std::string color;
  std::string preproc;
  std::string mix;
  std::string sessionName;
  int port;
  int analog;
  int audio;
  bool useeffects;
  int efflen; //length of effect buffer
  std::string addr; //IP ADDRESS
  int proclen; //length of processing buffer
  static std::string get_word(std::string line);

};

#endif //PARSER_HPP
