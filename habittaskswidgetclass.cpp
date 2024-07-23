#include "habittaskswidgetclass.h"
#include "stylehelper.h"

HabitTasksWidgetClass::HabitTasksWidgetClass(QString& name, QWidget *parent)
    : QWidget{parent}, name(name)
{
    lbl = new QLabel(name);
    lbl->setStyleSheet("font-family: 'Roboto Mono';"
                  "font-size: 15px;"
                  "background-color: black;");

    completeBtn = new QPushButton("complete");
    completeBtn->setStyleSheet(stylehelper::getAddButtonStyle());
    deleteBtn = new QPushButton("delete");
    deleteBtn->setStyleSheet(stylehelper::getAddButtonStyle());

    myHLayout = new QHBoxLayout;
    myVLayout = new QVBoxLayout;


    setFixedSize(400,150);
    setStyleSheet("background-color: white;");


    myHLayout->addWidget(completeBtn);
    myHLayout->addWidget(deleteBtn);
    myVLayout->addWidget(lbl);
    myVLayout->addLayout(myHLayout);

    setLayout(myVLayout);


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
