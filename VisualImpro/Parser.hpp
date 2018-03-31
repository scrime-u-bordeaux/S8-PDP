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
  std::string getCoeff() const;
  std::string getColor() const;
  std::string getPreproc() const;
  std::string getMix() const;
  std::string getAddress() const;
  int getAnalog() const;
  int getAudio() const;
  int getPort() const;
  int getProcessLength() const;
  int getUseEffects() const;
  int getEffectLen() const;
  std::string getSessionName() const;
  std::list<std::string> getTracks() const;

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
