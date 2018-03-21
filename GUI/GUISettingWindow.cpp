#include "GUISettingWindow.hpp"

GUISettingWindow::GUISettingWindow(QWidget *parent) : QDialog(parent){
    finishButton = new QPushButton("FIN");
    finishButton->setDefault(true);
    connect(finishButton, SIGNAL(clicked()), this, SLOT(accept()));
    principalWidget = new QWidget;

    mainLayout = new QGridLayout;
    mainLayout->addWidget(finishButton, 0, 0);

    setLayout(mainLayout);
}

GUISettingWindow::~GUISettingWindow(){
    delete(finishButton);
    delete(principalWidget);
    delete(mainLayout);
}
