/**
 *  @file    parse.cpp
 *  @author  Jérémy LIXANDRE
 *  @date    July 2017
 *
 *  @section DESCRIPTION
 *
 *  This code contains functions used by the Parser object to iterate through
 *  string parameters given to the program.
 *
 */

#include "parse.hpp"
#include <cctype>
#include <cstring>
#include <iostream>

string get_next_word(string::iterator * it){
  string str("");
  while((**it != ' ') && ((**it)!= ',') && ((**it)!= '\0')){
    char c = *((*it)++);
    str+=c;}
  return str;
}

string get_next(string::iterator * it){
  string str("");
  if((**it)!= '\0'){
    char c = *((*it)++);
    str+=c;
  }
  return str;
}

string get_current(string::iterator *it){
  string str("");
  str+= **it;
  return str;
}

string get_next_by_name(string::iterator * it, string name){
  string str("");
  unsigned int i = 0;
  while ((i < (name.length())) &&  (name[i] == *((*it)++))){
      str+=name[i];
      i++;
    }
  if (str == name)
    return str;
  else
    return string("");
}

string get_next_name(string::iterator * it){
  string ret = get_next_word(it);
  if(is_name(ret)){
    return ret;
  }
  else
    return string("");
}

bool is_number(string str){
for (string::iterator it = str.begin(); it!=str.end(); ++it){
    if(!isdigit(*it)){
      return false;
    }
  }
  return true;
}

bool is_name(string str){
  for (string::iterator it = str.begin(); it!=str.end(); ++it){
    if((!isdigit(*it))&&(!isalpha(*it))){
      return false;
    }
  }
  return true;
}

bool is_end(string::iterator * it){
  return (**it == '\0');
}

bool is_ip(const string addr){
	struct sockaddr_in sa;
    int result = inet_pton(AF_INET, addr.c_str(), &(sa.sin_addr));
    return result != 0;
}
