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
    T getCase(int x, int y) const;
    void setCase(int x, int y, T val);
    int getSize() const;
    vector<T> getColumn(int index) const;
    void setColumn(int index, vector<T> column);
    string toString();
    virtual ~SquareMatrix();

private:
    int _sizeMatix;
    vector<vector<T> > _matrix;
};
#endif // DEF_MATRIX
