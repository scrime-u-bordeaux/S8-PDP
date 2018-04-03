#ifndef DEF_MATRIX
#define DEF_MATRIX

#include <string>
#include <vector>
#include "RGB.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

template <class T>
/**
 * \class Matrix
 * \brief Class representing a matrix with rows and columns.
 *
 * This class is used several times for processing buffers of signals.
 */
class Matrix {

public:
  /**
   * \fn    Matrix(int sizeMatix)
   * \brief Constructor of a squared matrix with default values.
   *
   * \param sizeMatix The matrix's size.
   *
   * Basic constructor of the Matrix class.
   */
  Matrix(int sizeMatix);

  /**
   * \fn    Matrix(int sizeMatix, vector<T> vec)
   * \brief Constructor of a matrix.
   *
   * \param sizeMatix, vec The number of rows and the value of each row.
   *
   * Constructor of the Matrix class with a size and a vector.
   */
  Matrix(int sizeMatix, vector<T> vec);

  /**
   * \fn    Matrix(int sizeMatix, T value)
   * \brief Constructor of a squared matrix with a specified value.
   *
   * \param sizeMatix, value The matrix's size and the value for each case.
   *
   * Constructor of the Matrix class with a size and a value assigned to each
   * case of the constructed squared matrix.
   */
  Matrix(int sizeMatix, T value);

  /**
   * \fn     T getCase(int x, int y) const
   * \brief  Get the case at coordonates (x,y).
   *
   * \param  x, y The coordonates of the matrix's case.
   * \return The value of the case of coordonates (x,y).
   */
  T getCase(int x, int y) const;

  /**
   * \fn     void setCase(int x, int y, T val)
   * \brief  Set the case at coordonates (x,y).
   *
   * \param  x, y, val The coordonates of the matrix's case and a value.
   *
   * Assign the value val to the case of coordonates (x,y).
   */
  void setCase(int x, int y, T val);

  /**
   * \fn     int getSize() const
   * \brief  Get the size of the matrix.
   *
   * \return An integer corresponding to the matrix's size.
   */
  int getSize() const;

  /**
   * \fn     vector<T> getRow(int index) const
   * \brief  Get the row number index.
   *
   * \param  index The index from where to return the vector of the matrix's
   *         row.
   * \return The vector corresponding to the row at the index given in
   *         parameter.
   */
  vector<T> getRow(int index) const;

  /**
   * \fn     vector<T>& getRowRef(int index)
   * \brief  Get the reference of the row number index.
   *
   * \param  index The index from where to return the reference of the vector of
   *         the matrix's row.
   * \return The vector corresponding to the reference of the row at the index
   *         given in parameter.
   */
  vector<T>& getRowRef(int index);

  /**
   * \fn     void setRow(int index, vector<T> row)
   * \brief  Set the row number index with another vector.
   *
   * \param  index, row The index from where to set the row of the matrix with
   *         the vector called row.
   */
  void setRow(int index, vector<T> row);

  /**
   * \fn     vector<vector<T> > getMatrix()
   * \brief  Get the entire matrix.
   *
   * \return The matrix itself.
   */
  vector<vector<T> > getMatrix():

  /**
   * \fn     vector<vector<T> >& getMatrixRef()
   * \brief  Get a reference to the entire matrix.
   *
   * \return A reference to the matrix itself.
   */
  vector<vector<T> >& getMatrixRef();

  /**
   * \fn     void swap(Matrix<T>& mat)
   * \brief  Swap the matrix with another one.
   *
   * \param  mat The matrix to swap with our matrix.
   */
  void swap(Matrix<T>& mat);

  /**
   * \fn     string toString()
   * \brief  Print the content of the matrix.
   *
   * \return The content of the matrix into a string.
   */
  string toString();

  /**
   * \fn    virtual ~Matrix()
   * \brief Destructor.
   *
   * Destructor of the Matrix class.
   */
  virtual ~Matrix();

private:

    int _sizeMatix;
    vector<vector<T> > _matrix;
};
#endif // DEF_MATRIX
