#ifndef PARSE_HPP
#define PARSE_HPP

#include <string>
#include <arpa/inet.h>

#define NEXTCHAR(ite,sign) (get_next(ite) == sign)
#define SPACE(ite) (get_next_by_name(ite, " ") != "")
#define COOR(ite) (get_next_coordinate(ite) != "")
#define COMA(ite) (get_next(ite) == ",")
#define EQUALS(ite, name) (get_next_by_name(ite, name) != "")

std::string get_next_word(std::string::iterator * it);
std::string get_next(std::string::iterator * it);
std::string get_current(std::string::iterator *it);
std::string get_next_name(std::string::iterator * it); //get a name or empty string
std::string get_next_by_name(std::string::iterator * it, std::string name); //returns "name" if the next string after it is "name", empty string else else.

bool is_number(std::string str);
bool is_name(std::string str);
bool is_end(std::string::iterator * it);
bool is_ip(std::string str);

#endif //PARSE_HPP
