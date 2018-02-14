#ifndef DEF_RGB
#define DEF_RGB

#include <iostream>
#include <string>

using namespace std;

class RGB {
public:
  RGB(int red, int green, int blue);
  string toString();
  int getRed();
  int getGreen();
  int getBlue();
  ~RGB();

private:
  int _red, _green, _blue;
};
#endif // DEF_RGB
