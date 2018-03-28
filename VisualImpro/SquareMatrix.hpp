/**
 * @file SquareMatrix.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_MATRIX
#define DEF_MATRIX

#include "RGB.hpp"
#include <vector>
#include <string>

using namespace std;

template <class T>
class SquareMatrix {
public:
    SquareMatrix(int sizeMatix);
    SquareMatrix(int sizeMatix, vector<T> vec);
    T getCase(int x, int y) const;
    void setCase(int x, int y, T val);
    int getSize() const;
    vector<T> getColumn(int index) const;
    vector<T>& getColumnRef(int index);
    void setColumn(int index, vector<T> column);
    void swap(SquareMatrix<T>& mat);
    string toString();
    virtual ~SquareMatrix();

private:
    int _sizeMatix;
    vector<vector<T> > _matrix;
};
#endif // DEF_MATRIX
