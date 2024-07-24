#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //auto setting Functions
    setFont();

    //initializations
    mainVLayout              =  new QVBoxLayout();
    mainHLayout              =  new QHBoxLayout();
    m_pTableArea             =  new QWidget(this);
    m_pListArea              =  new QWidget(this);
    m_pListVLayout           =  new QVBoxLayout(m_pListArea);
    m_pTableWidgetClassModel =  new TableWidgetClassModel();
    m_pGreetAreaWidget       =  new GreetWidgetClass();
    tableView                =  new QTableView(m_pTableArea);


    //sizing
    m_pTableArea->setFixedSize(1100, 650);
    m_pListArea ->setFixedSize(400,  800);


    //configurateListArea
    m_pListArea   ->setStyleSheet("background-color: green;");
    m_pListVLayout->setContentsMargins(0,0,0,0);
    m_pListVLayout->setSpacing(0);
    m_pListVLayout->setAlignment(Qt::AlignTop);
    m_pListArea   ->setLayout(m_pListVLayout);


    //setting tableView
    tableView->setFixedSize(1100, 650);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()  ->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableView->setModel(m_pTableWidgetClassModel);

    //setting right configurate to Layouts
    mainVLayout->setContentsMargins(0,0,0,0);
    mainVLayout->setSpacing(0);
    mainHLayout->setContentsMargins(0,0,0,0);
    mainHLayout->setSpacing(0);

    //setting Layouts
    mainVLayout->addWidget(m_pGreetAreaWidget);
    mainVLayout->addWidget(m_pTableArea);
    mainHLayout->addLayout(mainVLayout);
    mainHLayout->addWidget(m_pListArea);
    setLayout(mainHLayout);

    //connectings
    connect(m_pGreetAreaWidget->getMyDialog(), &myDialogWidget::mySignal,
            this, &Widget::onAddButtonClicked);
}
Widget::~Widget() {}


//slots
void Widget::onAddButtonClicked()
{
    QString txt = m_pGreetAreaWidget->getMyDialog()->getTextFromLineEdit();
    m_pTableWidgetClassModel->addHabit(txt, QVector<int>{});
    HabitTasksWidgetClass* newHabit = new HabitTasksWidgetClass(txt);
    m_pMyHabits.push_back(newHabit);
    m_pListVLayout->addWidget(newHabit);
    connect(newHabit,
            &HabitTasksWidgetClass::CompleteHabitSignal, this, &Widget::onCompleteButtonClicked);
    connect(newHabit,
            &HabitTasksWidgetClass::DeleteHabitSignal, this, &Widget::onDeleteButtonClicked);
}

void Widget::onDeleteButtonClicked(HabitTasksWidgetClass* received)
{
    changeCellColor("red", received);
}

void Widget::onCompleteButtonClicked(HabitTasksWidgetClass* received)
{
    changeCellColor("green", received);
}


//functions
void Widget::setFont()
{
    int id = QFontDatabase::addApplicationFont(":/new/fonts/resources/RobotoMono-VariableFont_wght.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    qDebug()<<family;
}

void Widget::changeCellColor(QString color, HabitTasksWidgetClass* received)
{
    int i = m_pMyHabits.indexOf(received);
    QModelIndex index = m_pTableWidgetClassModel->index(i, 0);
    m_pTableWidgetClassModel->setData(index , color, Qt::UserRole);
    m_pListVLayout->removeWidget(received);
    m_pMyHabits[i]->setEnabled(true);
    received->deleteLater();
}
