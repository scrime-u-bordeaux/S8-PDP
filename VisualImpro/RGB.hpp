#ifndef DEF_RGB
#define DEF_RGB

#include <iostream>

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
  string to_String();
  ~RGB();

private:
  int _red, _green, _blue;
};

/* surcharge l'operateur << afin de pouvoir afficher le contenu de rgb*/
ostream & operator<<(ostream &flux, const RGB& rgb);

#endif // DEF_RGB
