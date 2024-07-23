#include "mydialogwidget.h"

myDialogWidget::myDialogWidget(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("New Widget");
    setFixedSize(500,500);
    setStyleSheet("background-color: grey;");

    m_pLineEdit = new QLineEdit;
    m_pPushButton = new QPushButton("add");
    m_pLineEdit2 = new QLineEdit;

    mainHLayout = new QHBoxLayout;
    mainVLayout = new QVBoxLayout;
    mainVLayout->addWidget(m_pLineEdit2);
    mainHLayout->addWidget(m_pLineEdit);
    mainHLayout->addWidget(m_pPushButton);
    mainVLayout->addLayout(mainHLayout);
    setLayout(mainVLayout);


    connect(m_pPushButton, SIGNAL(clicked()), this, SLOT(onAddClicked()));
}

//slots
void myDialogWidget::onAddClicked()
{
    // text = m_pLineEdit->text();
    emit mySignal();
}
