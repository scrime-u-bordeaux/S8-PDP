#include "Window.hpp"
#include <QApplication>
#include <QGraphicsScene>
#include <QRect>
#include <QtGui>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Window *window = new Window(5);
  window->show();

  return app.exec();
}
