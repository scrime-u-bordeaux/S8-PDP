/***** ProcessMulti.hpp *****/

#ifndef PROCESSMULTI_HPP
#define PROCESSMULTI_HPP

#include "Connection.hpp"

#include <vector>
#include <string>

class ProcessMulti{
	
public:
  virtual void process(std::vector<std::vector<float> > buffer, Connection conn) = 0;
  virtual ~ProcessMulti(){}
 };


#endif
