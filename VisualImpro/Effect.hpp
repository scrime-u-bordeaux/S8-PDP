#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <vector>
#include <string>

using namespace std;

class Effect{

public:
	virtual void apply(vector <float> & in, vector < float > & out) = 0;
	virtual ~Effect(){}

};


#endif //EFFECT_HPP
