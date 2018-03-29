#!/bin/bash

qmake -project -r -Wall
qmake-qt4 "OBJECTS_DIR = ./obj/" "MOC_DIR = ./obj/"  GUI.pro
make
