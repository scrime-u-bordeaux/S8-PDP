/**
 * @file SquareMatrix.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_MATRIX
#define DEF_MATRIX

#include <vector>
#include <string>

using namespace std;

template <class T>
class SquareMatrix {
public:
    SquareMatrix(int sizeMatix);
    T getCase(int x, int y);
    void setCase(int x, int y, T val);
    int getSize();
    string toString();
    ~SquareMatrix();

private:
    int _sizeMatix;
    vector<vector<T> > _matrix;
};
#endif // DEF_MATRIX
