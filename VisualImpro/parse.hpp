#ifndef PARSE_HPP
#define PARSE_HPP

#include <arpa/inet.h>
#include <string>

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

#define NEXTCHAR(ite,sign) (get_next(ite) == sign)
#define SPACE(ite) (get_next_by_name(ite, " ") != "")
#define COOR(ite) (get_next_coordinate(ite) != "")
#define COMA(ite) (get_next(ite) == ",")
#define EQUALS(ite, name) (get_next_by_name(ite, name) != "")

string get_next_word(string::iterator * it);
string get_next(string::iterator * it);
string get_current(string::iterator *it);

/**
 * \fn     string get_next_name(string::iterator * it)
 * \brief  Get a name or empty string
 *
 * \param  it An iterator iterating through names
 * \return A string corresponding to the next name the iterator goes on, can be
 *         an empty string if there is no name after.
 */
string get_next_name(string::iterator * it);

/**
 * \fn     string get_next_by_name(string::iterator * it, string name)
 * \brief  Check if the next string is equals to "name"
 *
 * \param  it An iterator iterating through names
 * \param  name A string for checking purposes
 * \return "name" if the next string after it is "name", or an empty string
 *         if not.
 */
string get_next_by_name(string::iterator * it, string name);

bool is_number(string str);
bool is_name(string str);
bool is_end(string::iterator * it);
bool is_ip(string str);

#endif //PARSE_HPP
