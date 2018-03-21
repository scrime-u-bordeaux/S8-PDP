/***** process/PreprocStrengthEnergy.cpp *****/

#include "../utilities.hpp"

#include <math.h>

using namespace std;

vector<float> strengthenergyenvelope(const vector<float>& f1, int frame){ //cuts f1 in blocks of length 'frame' and applies norm to get the energy of the signal
  int size = f1.size();
  int nbframes = 0;
  if(size%frame == 0)
  	{
  	nbframes = size/frame;
 	}
  else
  {
	nbframes = size/frame + 1;
  }
  vector<float> energ(nbframes, 0.0);
  float previous = 0;
  float current = 0;
  for (int i = 0; i < nbframes; i++){
	current = energy(f1, i*frame, min(i*frame + frame, size));
    energ[i] = max(0.0f, current-previous);
    previous = current;
  }
  return energ;
}

extern "C"{

std::vector< std::vector <float> > PreprocStrengthEnergy(const std::vector < std::vector<float> >& input){
	std::vector< std::vector <float> > buffer(input.size());
	for (int i = 0 ; i < input.size(); i++){
		buffer[i] = strengthenergyenvelope(input[i], 1024);
	}
	return buffer;
}

}
