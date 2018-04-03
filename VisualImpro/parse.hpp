#ifndef PARSE_HPP
#define PARSE_HPP

#include <arpa/inet.h>
#include <string>

using namespace std;

#define NEXTCHAR(ite,sign) (get_next(ite) == sign)
#define SPACE(ite) (get_next_by_name(ite, " ") != "")
#define COOR(ite) (get_next_coordinate(ite) != "")
#define COMA(ite) (get_next(ite) == ",")
#define EQUALS(ite, name) (get_next_by_name(ite, name) != "")

string get_next_word(string::iterator * it);
string get_next(string::iterator * it);
string get_current(string::iterator *it);

// Get a name or empty string
string get_next_name(string::iterator * it);

// Returns "name" if the next string after it is "name", empty string else else.
string get_next_by_name(string::iterator * it, string name);

bool is_number(string str);
bool is_name(string str);
bool is_end(string::iterator * it);
bool is_ip(string str);

#endif //PARSE_HPP
