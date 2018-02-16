#ifndef DEF_CASE
#define DEF_CASE

#include "RGB.hpp"
#include <QColor>
#include <QRect>
#include <QWidget>

#define ORIGIN_X 50
#define ORIGIN_Y 50
#define SQUARE_SIZE 200

class Case : public QWidget {
public:
  Case(int x, int y, QWidget *parent = 0);
  void updateColor(RGB rgb);
  ~Case();

signals:
protected:
  void paintEvent(QPaintEvent *event);

private:
  QRect *rect;
  QColor *color;
};
#endif // DEF_CASE
