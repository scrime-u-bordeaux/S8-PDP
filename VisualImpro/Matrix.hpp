#ifndef DEF_MATRIX
#define DEF_MATRIX

#include <string>
#include <vector>
#include "RGB.hpp"

using namespace std;

template <class T>
class Matrix {
public:
    Matrix(int sizeMatix);
    Matrix(int sizeMatix, vector<T> vec);
    Matrix(int sizeMatix, T value);
    T getCase(int x, int y) const;
    void setCase(int x, int y, T val);
    int getSize() const;
    vector<T> getRow(int index) const;
    vector<T>& getRowRef(int index);
    void setRow(int index, vector<T> column);
    void swap(Matrix<T>& mat);
    string toString();
    virtual ~Matrix();

private:
    int _sizeMatix;
    vector<vector<T> > _matrix;
};
#endif // DEF_MATRIX
