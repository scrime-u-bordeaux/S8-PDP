#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <string>
#include <vector>

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class Effect
 * \brief Abstract class for every effect.
 *
 * This abstract class is used to process effects on our signals. It works as
 * the parent class for any effect class, with the apply method consisting on
 * applying an effect from the In buffer to the Out buffer.
 */
class Effect{

public:
	virtual void apply(vector <float> & in, vector < float > & out) = 0;
	virtual ~Effect(){}

};


#endif //EFFECT_HPP
