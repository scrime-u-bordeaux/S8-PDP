#ifndef CORREL_HPP
#define CORREL_HPP

#include <fstream>
#include <queue>
#include <string>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include "Connection.hpp"
#include "Matrix.hpp"
#include "RGB.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class ProcessMultiCorrel
 * \brief An object containing every processing function
 *
 * This class is used to process signals sent from render.cpp
 */
class ProcessMultiCorrel{

public:
   /**
    * \fn    ProcessMultiCorrel(float (*coeffcorrel) (const vector<float>& s1,
    *                           const vector<float>& s2) = NULL,
    *                           RGB (*colorscale) (float coeff) = NULL,
    *                           Matrix<float>(*preproc)
    *                           (const Matrix<float>& buff) = NULL,
    *                           vector<float>(*mixLevel)
    *                           (const Matrix<float>& correlMatrix) = NULL)
    * \brief Constructor of the ProcessMultiCorrel object.
    *
    * \param coeffcorrel The correlation process function.
    * \param colorscale The coloration process function.
    * \param preproc The preprocessing process function.
    * \param mixLevel The mix process function.
    *
    * The constructor will set a pointer for every process function to its
    * class members variables.
    */
  ProcessMultiCorrel(float (*coeffcorrel) (const vector<float>& s1,
  const vector<float>& s2) = NULL, RGB (*colorscale) (float coeff) = NULL,
  Matrix<float>(*preproc) (const Matrix<float>& buff) = NULL,
  vector<float>(*mixLevel) (const Matrix<float>& correlMatrix) = NULL);

  /**
   * \fn    void process(const Matrix<float>& buffer,
   *                     vector<float>& meanCorrelations, Connection conn)
   * \brief Function calling sequentially every other processing function.
   *
   * \param buffer The signals buffer.
   * \param meanCorrelations A vector given as a pointer to get the mix values.
   * \param conn The object to send data to a Firefox web page.
   */
  void process(const Matrix<float>& buffer,
               vector<float>& meanCorrelations, Connection conn);

  /**
   * \fn    void setColor(RGB (*colorscale) (float coeff))
   * \brief Set the coloration function.
   *
   * \param colorscale The coloration function that will replace the actual one.
   */
  void setColor(RGB (*colorscale) (float coeff)){
    _colorscale = colorscale;
  }

  /**
   * \fn    void setPreproc(Matrix<float> (* preprocess)
   *                        (const Matrix<float>& buff))
   * \brief Set the preprocessing function.
   *
   * \param preprocess The preprocessing function that will replace the actual
   *                   one.
   */
  void setPreproc(Matrix<float> (* preprocess) (const Matrix<float>& buff)){
    _preprocess = preprocess;
  }

  /**
   * \fn    void setCoeff(float (*coeffcorrel) (const vector<float>& s1,
                                                const vector<float>& s2))
   * \brief Set the correlation function.
   *
   * \param coeffcorrel The correlation function that will replace the actual
   *                    one.
   */
  void setCoeff(float (*coeffcorrel) (const vector<float>& s1,
                                      const vector<float>& s2)){
    _coeffcorrel = coeffcorrel;
  }

  /**
   * \fn    void setMix(vector<float> (*mixLevel) (const Matrix<float>&
                                                   correlMatrix))
   * \brief Set the mix function.
   *
   * \param mixLevel The mix function that will replace the actual one.
   */
  void setMix(vector<float> (*mixLevel) (const Matrix<float>&
                                              correlMatrix)){
    _mixLevel = mixLevel;
  }

  /**
   * \fn     RGB (*getColor()) (float)
   * \brief  Get the coloration function.
   *
   * \return The actual coloration function.
   */
  RGB (*getColor()) (float){
    return _colorscale;
  }

  /**
   * \fn     Matrix<float> (* getPreproc()) (const Matrix<float>& buff)
   * \brief  Get the preprocessing function.
   *
   * \return The actual preprocessing function.
   */
  Matrix<float> (* getPreproc()) (const Matrix<float>& buff){
    return _preprocess;
  }

  /**
   * \fn     float (*getCoeff()) (const vector<float>& s1,
                                  const vector<float>& s2)
   * \brief  Get the correlation function.
   *
   * \return The actual correlation function.
   */
  float (*getCoeff()) (const vector<float>& s1,
                       const vector<float>& s2){
    return _coeffcorrel;
  }

  /**
   * \fn     vector<float> (*getMix()) (const Matrix<float>& correlMatrix)
   * \brief  Get the mix function.
   *
   * \return The actual mix function.
   */
  vector<float> (*getMix()) (const Matrix<float>& correlMatrix){
    return _mixLevel;
  }

  /**
   * \fn    virtual ~ProcessMultiCorrel()
   * \brief Destructor.
   *
   * Destructor of the ProcessMultiCorrel class.
   */
  virtual ~ProcessMultiCorrel();

private :
  float (*_coeffcorrel) (const vector<float>& s1,
                         const vector<float>& s2);
  RGB (*_colorscale) (float coeff);
  Matrix<float> (* _preprocess) (const Matrix<float>& buff);
  vector<float> (*_mixLevel)(const Matrix<float>& correlMatrix);
  Matrix<float> calcul_correl(const Matrix<float>& buffer);
  void process_volume(const Matrix<float>& correlMatrix,
                      vector<float>& meanCorrelations);
  Matrix<RGB> color_matrix(const Matrix<float>& correlMatrix);
  ofstream matrixfile;
};

#endif //SIMPLECORREL_HPP
