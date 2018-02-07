/***** Echo.hpp *****/

#ifndef ECHO_HPP
#define ECHO_HPP

#include <queue>
#include <vector>
#include "Effect.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;

class Echo : public Effect {

public :
  Echo(int offset, float amp) : _offset(offset), /*_count(0),*/ _amplitude(amp) { //offset in samples
    for (int k = 0; k < _offset; k++){
  	_samples.push(0.0);
  }
  }

  void apply(vector <float>& in, vector<float>& out){
    for (int i = 0; i < in.size(); i++){
      /*if(_count < _offset){
		out[i] = in[i];
		_count++;
      }
      else{*/
		out[i] = in[i] + _amplitude * _samples.front();
		_samples.pop();
      //}
      _samples.push(in[i]);           
    //}
    //usleep(1);
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
