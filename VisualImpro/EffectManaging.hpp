/***** EffectManaging.hpp *****/

#ifndef EFFECTMANAGING_HPP
#define EFFECTMANAGING_HPP

#include <assert.h>
#include <vector>

typedef void (*effectprocess) (std::vector<std::vector <float> > &, std::vector<std::vector <float> > &);

void genEffect(std::vector<std::vector <float> > & In, int indIn, std::vector<std::vector <float> > & Out, int indOut, int size, int globsize, effectprocess effect){
	assert(In.size() == Out.size());
	std::vector<std::vector <float> > tmpIn(In.size(), std::vector <float> (size, 0.0));
	std::vector<std::vector <float> > tmpOut(In.size(), std::vector <float> (size, 0.0));
	for (int i = 0 ; i < size; i++){
		for (int j = 0 ; j < In.size(); j++){
			tmpIn[j][i] = In[j][(indIn + i)%globsize];
		}
	}
	effect(tmpIn, tmpOut);
	
	for (int i = 0 ; i < size; i++){
		for (int j = 0 ; j < In.size(); j++){
			Out[j][(indOut + i)%globsize] = tmpOut[j][i];
		}
	}
}


#endif //EFFECTMANAGING_HPP