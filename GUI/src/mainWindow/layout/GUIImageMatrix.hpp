/**
 * \file GUIImageMatrix.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/
#ifndef DEF_GUIImageMatrix
#define DEF_GUIImageMatrix

#include <QGraphicsScene>
#include <QImage>
#include <QtGui>
#include <QWidget>
#include <vector>
#include "RGB.hpp"

#define SQUARE_SIZE 200

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class GUIImageMatrix
 * \brief Class containing the scene with the imagePix.
 *
 * The GUI Image window showing the RGB matrix in the scene.
 */
class GUIImageMatrix : public QGraphicsView {

  /**
   * \var Q_OBJECT Contains a Qt object.
   */
  Q_OBJECT
public:
  /**
   * \fn    GUIImageMatrix(int sizeMatrix, QWidget *parent = 0)
   * \brief Create the RGB image matrix
   *
   * \param sizeMatrix Size of the matrix.
   * \param parent     The QWidget parent.
   */
  GUIImageMatrix(int sizeMatrix, QWidget *parent = 0);

  /**
   * \fn    void updateColor(const vector<vector<RGB> >& matrixRGB)
   * \brief Update the colors of the matrix
   *
   * \param matrixRGB The RGB matrix with the fresh colors to update.
   */
  void updateColor(const vector<vector<RGB> > &matrixRGB);

  /**
   * \fn    ~GUIImageMatrix()
   * \brief Destructor
   *
   * Destructor of the GUIImageMatrix class.
   */
  ~GUIImageMatrix();

private:

  /**
   * \var imagePix All the RGB squares representing the matrix.
   * \var scene    The scene containing imagePix.
   */
  QPixmap *imagePix;
  QGraphicsScene *scene;
};
#endif // DEF_GUIImageMatrix
