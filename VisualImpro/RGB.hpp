#ifndef DEF_RGB
#define DEF_RGB

#include <iostream>
#include <string>

using namespace std;

class RGB {
public:
  RGB(int red, int green, int blue);
  int getRed() const;
  int getGreen() const;
  int getBlue() const;
  void setRed(int red);
  void setGreen(int green);
  void setBlue(int blue);
  string toString();
  string colortohexa(int color);
  unsigned long createRGB(int r, int g, int b);
  ~RGB();

private:
  int _red, _green, _blue;
};

// surcharge l'operateur << afin de pouvoir afficher le contenu de rgb
ostream & operator<<(ostream &flux, const RGB& rgb);

#endif // DEF_RGB
