#ifndef DEF_WINDOW
#define DEF_WINDOW

#include "RGB.hpp"
#include <QtGui>


class Window : public QGraphicsView {
public:
  Window(int sizeMatrix, QGraphicsScene scene);
  void update(std::vector<std::vector<RGB> > colorMatrix);
  ~Window();

private:
};
#endif // DEF_WINDOW
