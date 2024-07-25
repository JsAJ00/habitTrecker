#include "mydialogwidget.h"

myDialogWidget::myDialogWidget(QWidget *parent)
    : QWidget{parent}
{
    //main settings
    setWindowTitle("New Widget");
    setFixedSize(500,500);
    setStyleSheet("background-color: grey;");


    //initializations
    m_pLineEdit     = new QLineEdit;
    m_pPushButton   = new QPushButton("add");
    mainHLayout     = new QHBoxLayout;


    //layouts setting
    mainHLayout->addWidget(m_pLineEdit);
    mainHLayout->addWidget(m_pPushButton);
    setLayout(mainHLayout);


    //connectings
    connect(m_pPushButton, SIGNAL(clicked()), this, SLOT(onAddClicked()));
}


//slots
void myDialogWidget::onAddClicked()
{
    emit mySignal();
}


//functions
QString myDialogWidget::getTextFromLineEdit(){
    return m_pLineEdit->text();
}
