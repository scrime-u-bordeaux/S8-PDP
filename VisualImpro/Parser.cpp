#include "Parser.hpp"


Parser::Parser(std::string file) : _file(file), port(0), analog(0), audio(0), useeffects(false), efflen(DEFAULT_EFFECT_LEN), proclen(DEFAULT_PROCESS_LEN) {

  //PARSES A CONFIG FILE WITH FILE NAMES AND FUNCTIONS TO USE
  //IF THERE ARE TOO MANY OCCURENCIES OF EACH ELEMENT (ex: 2 lines with COLOR), THE LAST LINE IS KEPT

  std::ifstream ifs (file, std::ifstream::in);
  std::string line;
  std::string word;
  while (ifs){
    getline(ifs, line);
    if (line.find("FILE ") == 0){
      std::string word = get_word(line);
      if (word.find(".wav") == (word.size() - 4)){	
	tracks.push_back(word);
      }
    }
    else if (line.find("COEFF ") == 0 && ((word = get_word(line)).find("Coeff") == 0)){
      coeff = word;
    }
    else if (line.find("COLOR ") == 0 && ((word = get_word(line)).find("Color") == 0)){
      color = word;
    }
    else if (line.find("PREPROC ") == 0 && ((word = get_word(line)).find("Preproc") == 0)){
      preproc = word;
    }
    else if (line.find("MIX ") == 0 && ((word = get_word(line)).find("Mix") == 0)){
      mix = word;
    }        
    else if (line.find("ADDRESS ") == 0 && ( is_ip(word = get_word(line)) )){
      addr = word;
    }
    else if (line.find("PROCESSLEN ") == 0 && (  is_number(word = get_word(line))  )){
		if (std::stoi(word) > 0)
		{
	      proclen = std::stoi(word);
		}
    }
    else if (line.find("PORT ") == 0 && (  is_number(word = get_word(line))  )){
      port = std::stoi(word);
    }
	else if (line.find("ANALOG ") == 0 && (  is_number(word = get_word(line))  )){
		if (std::stoi(word) >= 0 && std::stoi(word) <= NB_ANALOG_MAX)
			{
		      analog = std::stoi(word);
			}
    }
    else if (line.find("AUDIO ") == 0 && (  is_number(word = get_word(line))  )){
		if (std::stoi(word) >= 0 && std::stoi(word) <= NB_AUDIO_MAX)
			{
		      audio = std::stoi(word);
			}
    }
    else if (line.find("EFFECTS ") == 0 && (  ((word = get_word(line)) == "YES") || (word == "Y") || (word=="OUI") || (word=="O") )){
      useeffects = true;
    }
    else if (line.find("EFFECT_BUFFER_LEN ") == 0 && (  is_number(word = get_word(line)) )){
      	if(std::stoi(word) > DEFAULT_EFFECT_LEN){
	      	efflen = std::stoi(word);
      	}
    }
    else if (line.find("TITLE ") == 0){
      sessionName = get_word(line);
    }
    else if (line.find("#") == 0){
    //rien du tout parce que c'est les commentaires lel
    }
  }
  ifs.close();
}

int Parser::getProcessLength(){
  return proclen;
}

std::string Parser::get_word(std::string line){
  std::string::iterator it = line.begin();
  get_next_word(&it);
  get_next(&it);
  while(*it == ' '){
    it++;
  }
  return get_next_word(&it); 
}

std::string Parser::getCoeff(){
  return coeff;
}
std::string Parser::getColor(){
  return color;
}

std::string Parser::getPreproc(){
  return preproc;
}

std::string Parser::getMix(){
  return mix;
}

std::list<std::string> Parser::getTracks(){
  return tracks;
}

std::string Parser::getAddress(){
	return addr;
}

int Parser::getPort(){
	return port;
}

int Parser::getAnalog(){
	return analog;
}

int Parser::getAudio(){
	return audio;
}

int Parser::getUseEffects(){
	return useeffects;
}

int Parser::getEffectLen(){
	return efflen;
}

std::string Parser::getSessionName(){
	return sessionName;
}
