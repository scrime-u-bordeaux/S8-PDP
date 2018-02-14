// Generate a constant sound volume mix, not depending on correlations

#include "../utilities.hpp"

extern "C"{

float MixMaxCorrelated(float correlValue){

	return correlValue;

}

}
