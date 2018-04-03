/**
 * @file GUIFileSettingBuilder.hpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUIFILESETTINGBUILDER
#define DEF_GUIFILESETTINGBUILDER

#include <string>

using namespace std;

class GUIFileSettingBuilder {

public:
    virtual void beginFile() = 0;
    virtual void addPort(int port) = 0;
    virtual void addAddress(string address) = 0;
    virtual void addProcessLen(int length) = 0;
    virtual void addEffect(bool effect, int bufferLen) = 0;
    virtual void addAnalogInput(int nb) = 0;
    virtual void addAudioInput(int nb) = 0;
    virtual void addWavFile(string path) = 0;
    virtual void addColorFunction(string functionName) = 0;
    virtual void addCoeffFunction(string functionName) = 0;
    virtual void addPreProcFunction(string functionName) = 0;
    virtual void addMixFunction(string functionName) = 0;
    virtual void endFile() = 0;
};
#endif // DEF_GUIFILESETTINGBUILDER
