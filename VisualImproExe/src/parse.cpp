#include "parse.hpp"
#include <cctype>
#include <cstring>
#include <iostream>

std::string get_next_word(std::string::iterator * it){
  std::string str("");
  while((**it != ' ') && ((**it)!= ',') && ((**it)!= '\0')){
    char c = *((*it)++);
    str+=c;}
  return str;
}

std::string get_next(std::string::iterator * it){
  std::string str("");
  if((**it)!= '\0'){
    char c = *((*it)++);
    str+=c;
  }
  return str;
}

std::string get_current(std::string::iterator *it){
  std::string str("");
  str+= **it;
  return str;
}

std::string get_next_by_name(std::string::iterator * it, std::string name){
  std::string str("");
  unsigned int i = 0;
  while ((i < (name.length())) &&  (name[i] == *((*it)++))){
      str+=name[i];
      i++;
    }
  if (str == name)
    return str;
  else 
    return std::string("");
}

std::string get_next_name(std::string::iterator * it){
  std::string ret = get_next_word(it);
  if(is_name(ret)){
    return ret;
  }
  else
    return std::string("");
}

bool is_number(std::string str){
for (std::string::iterator it = str.begin(); it!=str.end(); ++it){
    if(!isdigit(*it)){
      return false;
    }
  }
  return true;
}

bool is_name(std::string str){
  for (std::string::iterator it = str.begin(); it!=str.end(); ++it){
    if((!isdigit(*it))&&(!isalpha(*it))){
      return false;
    }
  }
  return true;
}

bool is_end(std::string::iterator * it){
  return (**it == '\0');
}

bool is_ip(const std::string addr){
	struct sockaddr_in sa;
    int result = inet_pton(AF_INET, addr.c_str(), &(sa.sin_addr));
    return result != 0;
}
