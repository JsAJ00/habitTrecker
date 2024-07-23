#include "greetwidgetclass.h"
#include "stylehelper.h"

GreetWidgetClass::GreetWidgetClass(QWidget *parent)
    : QWidget{parent}
{
    m_pDialogWidget = new myDialogWidget;
    mainWidget = new QWidget(this);
    m_pGreetLabel = new QLabel("Good afternoon, Oleksiy!");
    m_pAddHabitButton = new QPushButton("+ Add habit");
    m_pGreetAndHabitHLayout = new QHBoxLayout;
    m_pGHabitVLayout = new QVBoxLayout;


    mainWidget->setFixedSize(1100, 150);
    mainWidget->setStyleSheet("background-color: grey;");

    m_pAddHabitButton->setFixedSize(150, 35);
    m_pAddHabitButton->setStyleSheet(stylehelper::getAddButtonStyle());

    //setting button to down right corner
    m_pGHabitVLayout->addStretch();
    m_pGHabitVLayout->addWidget(m_pAddHabitButton);

    m_pGreetAndHabitHLayout->addWidget(m_pGreetLabel);
    m_pGreetAndHabitHLayout->addLayout(m_pGHabitVLayout);

    mainWidget->setLayout(m_pGreetAndHabitHLayout);


    connect(m_pAddHabitButton, SIGNAL(clicked()), this, SLOT(onAddHabitButtonClicked()));
}
//slots
void GreetWidgetClass::onAddHabitButtonClicked()
{
    qDebug()<<"hello";
    createDialog();
}


//functions
void GreetWidgetClass::createDialog()
{
    m_pDialogWidget->show();
}

