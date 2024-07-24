#include "mydialogwidget.h"

myDialogWidget::myDialogWidget(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("New Widget");
    setFixedSize(500,500);
    setStyleSheet("background-color: grey;");

    m_pLineEdit = new QLineEdit;
    m_pPushButton = new QPushButton("add");

    mainHLayout = new QHBoxLayout;
    mainHLayout->addWidget(m_pLineEdit);
    mainHLayout->addWidget(m_pPushButton);
    setLayout(mainHLayout);


    connect(m_pPushButton, SIGNAL(clicked()), this, SLOT(onAddClicked()));
}

//slots
void myDialogWidget::onAddClicked()
{
    // text = m_pLineEdit->text();
    emit mySignal();
}
