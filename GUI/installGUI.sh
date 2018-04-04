#!/bin/bash

qmake -project -Wall
qmake-qt4 "QMAKE_CXXFLAGS += -std=c++11 -Wall" \
 "OBJECTS_DIR = ./obj/" \
 "MOC_DIR = ./obj/" \
 "DESTDIR = ./bin" \
 "QT += network" \
 "DEPENDPATH += ../VisualImpro/" \
 "INCLUDEPATH += ../VisualImpro/" \
 "SOURCES += RGB.cpp" \
 "HEADERS += RGB.hpp"
  GUI.pro
make
