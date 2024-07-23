#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtAlgorithms>
#include "greetwidgetclass.h"
#include "habittaskswidgetclass.h"
#include "tablewidgetclassmodel.h"
#include "tabledeligateclass.h"

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

    QString text;
    QHBoxLayout* mainHLayout;
    QVBoxLayout* mainVLayout;

    GreetWidgetClass* m_pGreetAreaWidget;
    QTableView* tableView;
    TableWidgetClassModel* m_pTableWidgetClassModel;

    QList<HabitTasksWidgetClass*> m_pMyHabits;
    QVBoxLayout* m_pListVLayout;
    int indexOfHabit;

    void setFont();
    void setText(QString txt){
        text = txt;
    };
};
#endif // WIDGET_H
