// Generate the sound in output as it is given in input

#include "../utilities.hpp"

using namespace std;

extern "C"{

/*
vector <float> MixNeutral(int gSampleFactor, float coeff, BelaContext *context){

	int STANDARD_SAMPLE_RATE = 22050;

	int contextAnalogFrames = context->analogFrames;
	for(int n=0 ; n<contextAnalogFrames ; n++){
		if (gSampleFactor == STANDARD_SAMPLE_RATE){       
			audioWrite(context, 2*n, 0, audioRead(context, 2*n, 0));
    		        audioWrite(context, 2*n + 1, 0, audioRead(context, 2*n + 1, 0));
  		}
		else{
			audioWrite(context, n, 0, audioRead(context, n, 0));
    		}
		
		if (gSampleFactor == STANDARD_SAMPLE_RATE){
			audioWrite(context, 2*n, 1, audioRead(context, 2*n, 1));
    		        audioWrite(context, 2*n + 1, 1, audioRead(context, 2*n + 1, 1));
  		}
		else{
			audioWrite(context, n, 1, audioRead(context, n, 1));
    		}
	}

}*/

}
