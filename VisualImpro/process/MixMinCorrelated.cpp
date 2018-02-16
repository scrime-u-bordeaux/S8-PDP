// Generate a sound volume mix on each instrument depending on the least correlated instruments

#include "../utilities.hpp"

extern "C"{

/* float MixMinCorrelated(float correlValue){

	return 1-(1*correlValue);

} */

float generateNewVolume(float correlValue){

	return 1-(1*correlValue);

}

}
