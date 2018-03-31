/**
 * @file GUIFileSettingBuilder.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUIFILESETTINGBUILDER
#define DEF_GUIFILESETTINGBUILDER

#include <string>

using namespace std;

class GUIFileSettingBuilder {

public:
    virtual void beginFile() = 0;
    virtual void addSetting(string nameSetting, int value) = 0;
    virtual void addSetting(string nameSetting, string value) = 0;
    virtual void endFile() = 0;
};
#endif // DEF_GUIFILESETTINGBUILDER
