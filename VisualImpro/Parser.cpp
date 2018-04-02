/**
 *  @file    Parser.cpp
 *  @author  Jérémy LIXANDRE
 *  @date    July 2017
 *
 *  @section DESCRIPTION
 *
 *  Parses a config file with filenames and functions. It is used in main.cpp to
 *  fill a Channel settings structure with the parameters given to the program.
 *  It is also used to prevent the use of too many occurencies of each element
 *  (ex: 2 lines with COLOR). In this case, the last line is kept.
 *
 */

#include "Parser.hpp"

Parser::Parser(string file) : _file(file), port(0), analog(0), audio(0),
                              useeffects(false), efflen(DEFAULT_EFFECT_LEN),
                              proclen(DEFAULT_PROCESS_LEN){

  ifstream ifs (file, ifstream::in);
  string line;
  string word;
  while (ifs){
    getline(ifs, line);
    if (line.find("FILE ") == 0){
      string word = get_word(line);
      if (word.find(".wav") == (word.size() - 4)){
	       tracks.push_back(word);
      }
    }
    else if (line.find("COEFF ") == 0
             && ((word = get_word(line)).find("Coeff") == 0)){
      coeff = word;
    }
    else if (line.find("COLOR ") == 0
             && ((word = get_word(line)).find("Color") == 0)){
      color = word;
    }
    else if (line.find("PREPROC ") == 0
             && ((word = get_word(line)).find("Preproc") == 0)){
      preproc = word;
    }
    else if (line.find("MIX ") == 0
             && ((word = get_word(line)).find("Mix") == 0)){
      mix = word;
    }
    else if (line.find("ADDRESS ") == 0
             && (is_ip(word = get_word(line))){
      addr = word;
    }
    else if (line.find("PROCESSLEN ") == 0
             && (is_number(word = get_word(line)))){
		  if (stoi(word) > 0){
	      proclen = stoi(word);
		  }
    }
    else if (line.find("PORT ") == 0
             && (is_number(word = get_word(line)))){
      port = stoi(word);
    }
	  else if (line.find("ANALOG ") == 0
             && (is_number(word = get_word(line)))){
		  if (stoi(word) >= 0 && stoi(word) <= NB_ANALOG_MAX){
		    analog = stoi(word);
			}
    }
    else if (line.find("AUDIO ") == 0
             && (is_number(word = get_word(line)))){
		  if (stoi(word) >= 0 && stoi(word) <= NB_AUDIO_MAX){
		    audio = stoi(word);
			}
    }
    else if (line.find("EFFECTS ") == 0 &&
             (((word = get_word(line)) == "YES") || (word == "Y") ||
             (word=="OUI") || (word=="O"))){
      useeffects = true;
    }
    else if (line.find("EFFECT_BUFFER_LEN ") == 0
             && (is_number(word = get_word(line)))){
      if(stoi(word) > DEFAULT_EFFECT_LEN){
	      efflen = stoi(word);
      }
    }
    else if (line.find("TITLE ") == 0){
      sessionName = get_word(line);
    }
    else if (line.find("#") == 0){
      // skip comments
    }
  }
  ifs.close();
}

string Parser::get_word(string line){
  string::iterator it = line.begin();
  get_next_word(&it);
  get_next(&it);
  while(*it == ' '){
    it++;
  }
  return get_next_word(&it);
}

int Parser::getProcessLength() const{
  return proclen;
}

string Parser::getCoeff() const{
  return coeff;
}
string Parser::getColor() const{
  return color;
}

string Parser::getPreproc() const{
  return preproc;
}

string Parser::getMix() const{
  return mix;
}

list<string> Parser::getTracks() const{
  return tracks;
}

string Parser::getAddress() const{
	return addr;
}

int Parser::getPort() const{
	return port;
}

int Parser::getAnalog() const{
	return analog;
}

int Parser::getAudio() const{
	return audio;
}

int Parser::getUseEffects() const{
	return useeffects;
}

int Parser::getEffectLen() const{
	return efflen;
}

string Parser::getSessionName() const{
	return sessionName;
}
