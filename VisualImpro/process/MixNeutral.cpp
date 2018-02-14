// Generate the sound in output as it is given in input

#include "../utilities.hpp"

extern "C"{

void MixNeutral(void){

	int gSampleFactor = 1;
	gSampleFactor = gUserSet.sample_factor;
	int STANDARD_SAMPLE_RATE = 22050;
	// on a besoin de context

	int contextAnalogFrames = context->analogFrames;
	for(int i=0 ; i<contextAnalogFrames ; i++){
		if (gSampleFactor == STANDARD_SAMPLE_RATE){       
			audioWrite(context, 2*n, 0, out);
    		        audioWrite(context, 2*n + 1, 0, out);
  		}
		else{
			audioWrite(context, n, 0, out);
    		}
		
		if (gSampleFactor == STANDARD_SAMPLE_RATE){
			audioWrite(context, 2*n, 1, out);
    		        audioWrite(context, 2*n + 1, 1, out);
  		}
		else{
			audioWrite(context, n, 1, out);
    		}
	}

}

}
