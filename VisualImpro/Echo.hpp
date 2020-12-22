/**
 *  \file    Echo.hpp
 *  \author  Jérémy LIXANDRE
 *  \date    July 2017
 *
 *  \brief
 *
 *  The Echo code is and effect (inherited from Effect class), and applies the
 *  Echo effect from the buffer In to the buffer Out given in parameter.
 *
 */

#ifndef ECHO_HPP
#define ECHO_HPP

#include <queue>
#include <vector>
#include <unistd.h>

#include "Effect.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class Echo
 * \brief Class representing the echo effect.
 *
 * This class is used to apply an effect on a buffer and get the result in
 * another buffer.
 */
class Echo : public Effect {

public :
  Echo(int offset, float amp) : _offset(offset), /*_count(0),*/ _amplitude(amp){
    for (int k = 0; k < _offset; k++){
  	_samples.push(0.0);
    }
  }

  void apply(vector <float>& in, vector<float>& out){
    for (int i = 0; i < in.size(); i++){
      out[i] = in[i] + _amplitude * _samples.front();
      _samples.pop();
      _samples.push(in[i]);
    }
  }

  virtual ~Echo(){}

private :
  int _offset;
  //int _count;
  float _amplitude;
  queue <float> _samples;


};

#endif //ECHO_HPP
