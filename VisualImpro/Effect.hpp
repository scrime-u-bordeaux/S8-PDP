/***** Effect.hpp *****/

#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <vector>
#include <string>

class Effect{
	
public:
	virtual void apply(std::vector <float> & in, std::vector < float > & out) = 0;
	virtual ~Effect(){}
	
};


#endif //EFFECT_HPP