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
    void addSetting(string nameSetting, int value);
    void addSetting(string nameSetting, string value);
    void endFile();
    ~GUIConfigFileSettingBuilder();
};
#endif // DEF_GUICONFIGFILESETTINGBUILDER
