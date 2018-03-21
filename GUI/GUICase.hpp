#ifndef DEF_CASE
#define DEF_CASE

#include "RGB.hpp"
#include <QWidget>
#include <QColor>
#include <QRect>
#include <QPainter>

#define ORIGIN_X 50
#define ORIGIN_Y 50
#define SQUARE_SIZE 200

class Case : public QWidget {
public:
  Case(int x, int y, QWidget *parent = 0);
  void updateColor(RGB rgb);
  ~Case();

protected:
  void paintEvent(QPaintEvent *event = NULL);

private:
  QPainter painter;
  QRect *rect;
  QColor *color;
};
#endif // DEF_CASE
