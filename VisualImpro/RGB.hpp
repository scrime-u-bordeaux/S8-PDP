#ifndef DEF_RGB
#define DEF_RGB

#include <iostream>
#include <string>

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class RGB
 * \brief Class used for RGB triplets
 *
 * This class is composed by three integers whose values are ranged between 0
 * and 255 and respectively represents the red, green, and blue colors.
 */
class RGB {
public:
  /**
   * \fn    RGB(int red, int green, int blue)
   * \brief Constructor of the RGB object.
   *
   * \param red The red color respresented as an integer between 0 and 255.
   * \param green The green color respresented as an integer between 0 and 255.
   * \param blue The blue color respresented as an integer between 0 and 255.
   */
  RGB(int red, int green, int blue);

  /**
   * \fn    RGB(string hexaCode)
   * \brief Constructor of the RGB object from a string
   *
   * \param hexaCode A hexadecimal value as a string to construct a RGB object.
   */
  RGB(string hexaCode);

  /**
   * \fn     int getRed() const
   * \brief  Get the value of the red component.
   *
   * \return An integer between 0 and 255 corresponding to the red color.
   */
  int getRed() const;

  /**
   * \fn     int getGreen() const
   * \brief  Get the value of the green component.
   *
   * \return An integer between 0 and 255 corresponding to the green color.
   */
  int getGreen() const;

  /**
   * \fn     int getBlue() const
   * \brief  Get the value of the blue component.
   *
   * \return An integer between 0 and 255 corresponding to the blue color.
   */
  int getBlue() const;

  /**
   * \fn    void setRed(int red)
   * \brief Set the value of the red component.
   *
   * \param red A value ranged between 0 and 255 corresponding to the red color.
   */
  void setRed(int red);

  /**
   * \fn    void setGreen(int green)
   * \brief Set the value of the green component.
   *
   * \param red A value ranged between 0 and 255 corresponding to the green
   *            color.
   */
  void setGreen(int green);

  /**
   * \fn    void setBlue(int blue)
   * \brief Set the value of the blue component.
   *
   * \param red A value ranged between 0 and 255 corresponding to the blue
   *            color.
   */
  void setBlue(int blue);

  /**
   * \fn     string toString()
   * \brief  Print the content of the RGB object.
   *
   * \return The content of the RGB object into a string.
   */
  string toString();


  /**
   * \fn    virtual ~RGB()
   * \brief Destructor.
   *
   * Destructor of the RGB class.
   */
  virtual ~RGB();

private:
  int _red, _green, _blue;
};

/**
 * \fn    ostream & operator<<(ostream &flux, const RGB& rgb)
 * \brief Overload the operator<<
 *
 * \param flux The flux where the content will be written.
 * \param rgb  The RGB triplet to print into the flux.
 * \return An ostream containing the value of the RGB components.
 */
ostream & operator<<(ostream &flux, const RGB& rgb);

#endif // DEF_RGB
