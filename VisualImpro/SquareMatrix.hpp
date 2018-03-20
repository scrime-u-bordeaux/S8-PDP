#ifndef DEF_MATRIX
#define DEF_MATRIX

using namespace std;

template <typename T>
class SquareMatrix {
public:
    SquareMatrix<T>(int sizeMatix);
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
