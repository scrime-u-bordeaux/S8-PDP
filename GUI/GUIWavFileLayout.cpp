/**
 * @file GUIWavFileLayout.hpp
 * @author Lucas VIVAS
*/

#include "GUIWavFileLayout.hpp"

#include <iostream>
#include <QString>

GUIWavFileLayout::GUIWavFileLayout(QWidget *parent) : QGridLayout(parent){
    fileDialog = new QFileDialog();
    loadButton = new QPushButton("Load");
    loadButton->setToolTip("Load a .wav file");
    connect(loadButton, SIGNAL(clicked()), this, SLOT(loadWavFile()));
    this->addWidget(loadButton, 0, 0);
}

void GUIWavFileLayout::loadWavFile(){
    cout << "cacasa" << endl;
    QString filename = fileDialog->getOpenFileName(NULL, "Choisir un fichier wav", "/", "WAV files (*.wav*)"); //comprends pas NULL et pas this

}
GUIWavFileLayout::~GUIWavFileLayout(){

}
