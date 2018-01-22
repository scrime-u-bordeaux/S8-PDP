#ifndef PARSER_HPP
#define PARSER_HPP

#define EXECPATH "/root/Bela/projects/VisualImpro/"
#define WAVPATH "/root/Bela/projects/VisualImpro/wavfiles/tmp/"
#define CONFIGPATH "/root/Bela/projects/VisualImpro/config/"
#define LOGPATH "/root/Bela/projects/VisualImpro/log/"

#include "parse.hpp"
#include <list>
#include <iostream>
#include <fstream>
#include <unistd.h>

class ExecParser{

public :
  ExecParser(std::string filein, std::string fileout);
  ExecParser(){}
  ~ExecParser(){}
  std::list<std::string> getTracks();
  
private :
  std::string _filein, _fileout;
  std::list<std::string> tracks;
  static std::string get_word(std::string line);

};

#endif //PARSER_HPP
