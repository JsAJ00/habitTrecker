#include "habittaskswidgetclass.h"
#include "stylehelper.h"

HabitTasksWidgetClass::HabitTasksWidgetClass(QString& name, QWidget *parent)
    : QWidget{parent}, name(name)
{
    //initializations
    lbl         = new QLabel(name);
    completeBtn = new QPushButton("complete");
    deleteBtn   = new QPushButton("delete");
    myHLayout   = new QHBoxLayout;
    myVLayout   = new QVBoxLayout;


    //style settings
    lbl         ->setStyleSheet(stylehelper::getHabitTasksLabelStyle());
    lbl         ->setAlignment(Qt::AlignCenter);

    completeBtn ->setStyleSheet(stylehelper::getAddButtonStyle());
    deleteBtn   ->setStyleSheet(stylehelper::getAddButtonStyle());


    //main settings
    setFixedSize(450,150);
    setStyleSheet("background-color: white;");


    //setting Layouts
    myHLayout->addWidget(completeBtn);
    myHLayout->addWidget(deleteBtn);
    myVLayout->addWidget(lbl);
    myVLayout->addLayout(myHLayout);

    setLayout(myVLayout);


    //connectings
    connect(completeBtn, SIGNAL(clicked()),SLOT(onCompleteBtnClicked()));
    connect(deleteBtn, SIGNAL(clicked()),SLOT(ondeleteBtnClicked()));
}


//slots
void HabitTasksWidgetClass::onCompleteBtnClicked()
{
    emit CompleteHabitSignal(this);
}

void HabitTasksWidgetClass::ondeleteBtnClicked()
{
    emit DeleteHabitSignal(this);
}
