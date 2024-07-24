#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtAlgorithms>
#include "greetwidgetclass.h"
#include "habittaskswidgetclass.h"
#include "tablewidgetclassmodel.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void onAddButtonClicked();
    void onDeleteButtonClicked(HabitTasksWidgetClass* );
    void onCompleteButtonClicked(HabitTasksWidgetClass*);
private:
    QWidget* m_pTableArea;
    QWidget* m_pListArea;
    GreetWidgetClass* m_pGreetAreaWidget;

    QTableView* tableView;
    TableWidgetClassModel* m_pTableWidgetClassModel;
    QList<HabitTasksWidgetClass*> m_pMyHabits;

    QHBoxLayout* mainHLayout;
    QVBoxLayout* mainVLayout;
    QVBoxLayout* m_pListVLayout;

    void setFont();
    void setText(QString txt){
        text = txt;
    };
    void changeCellColor(QString color, HabitTasksWidgetClass* received);

    QString text;
    int indexOfHabit;
};
#endif // WIDGET_H
