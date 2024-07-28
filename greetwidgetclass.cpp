#include "greetwidgetclass.h"
#include "stylehelper.h"

GreetWidgetClass::GreetWidgetClass(QWidget *parent)
    : QWidget{parent}
{
    //initializations
    m_pDialogWidget         = new myDialogWidget;
    mainWidget              = new QWidget(this);
    m_pGreetLabel           = new QLabel("Good afternoon, Oleksiy!");
    m_pAddHabitButton       = new QPushButton("+ Add habit");
    m_pGreetAndHabitHLayout = new QHBoxLayout;
    m_pGHabitVLayout        = new QVBoxLayout;


    //mainWidget set
    mainWidget              ->setFixedSize(1040, 150);
    mainWidget              ->setStyleSheet("background-color: #424242;");


    //Greet Label set
    m_pGreetLabel->setStyleSheet(stylehelper::getHabitTasksLabelStyle());

    //AddButton set
    m_pAddHabitButton       ->setFixedSize(150, 35);
    m_pAddHabitButton       ->setStyleSheet(stylehelper::getAddButtonStyle());


    //moving button to down right corner
    m_pGHabitVLayout        ->addStretch();
    m_pGHabitVLayout        ->addWidget(m_pAddHabitButton);


    //setting Layouts
    m_pGreetAndHabitHLayout ->addWidget(m_pGreetLabel);
    m_pGreetAndHabitHLayout ->addLayout(m_pGHabitVLayout);

    mainWidget              ->setLayout(m_pGreetAndHabitHLayout);


    //connecting
    connect(m_pAddHabitButton, SIGNAL(clicked()), this, SLOT(onAddHabitButtonClicked()));
}


//slots
void GreetWidgetClass::onAddHabitButtonClicked()
{
    m_pDialogWidget->show();
}


//functions
myDialogWidget *GreetWidgetClass::getMyDialog(){
    return m_pDialogWidget;
}
