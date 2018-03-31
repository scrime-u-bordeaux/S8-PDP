/**
 * @file GUIConfigFileSettingBuilder.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUICONFIGFILESETTINGBUILDER
#define DEF_GUICONFIGFILESETTINGBUILDER

#include <string>

#include "GUIFileSettingBuilder.hpp"

using namespace std;

class GUIConfigFileSettingBuilder : public GUIFileSettingBuilder {

public:
    GUIConfigFileSettingBuilder();
    void beginFile();
    void addPort(int port);
    void addAddress(string address);
    void addProcessLen(int length);
    void addEffect(bool effect, int bufferLen);
    void addAnalogInput(int nb);
    void addAudioInput(int nb);
    void addWavFile(string path);
    void addColorFunction(string functionName);
    void addCoeffFunction(string functionName);
    void addPreProcFunction(string functionName);
    void addMixFunction(string functionName);
    void endFile();
    string getResult();
    ~GUIConfigFileSettingBuilder();

private:
    string* fileBuffer;
};
#endif // DEF_GUICONFIGFILESETTINGBUILDER
