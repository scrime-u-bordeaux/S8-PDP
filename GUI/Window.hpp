#ifndef DEF_WINDOW
#define DEF_WINDOW

#include "../VisualImpro/utilities.hpp"
#include <QtGui>

#define ORIGIN_X 50
#define ORIGIN_Y 50
#define SQUARE_SIZE 100

class Window : public QGraphicsView {
public:
  Window(int sizeMatrix);
  void update(std::vector<std::vector<Triplet> > colorMatrix);
  ~Window();

private:
  QGraphicsScene *scene;
};
#endif // DEF_WINDOW
