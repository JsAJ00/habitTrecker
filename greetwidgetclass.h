#ifndef GREETWIDGETCLASS_H
#define GREETWIDGETCLASS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>

#include "mydialogwidget.h"


class GreetWidgetClass : public QWidget
{
    Q_OBJECT
public:
    explicit GreetWidgetClass(QWidget *parent = nullptr);
    myDialogWidget* getMyDialog(){
        return m_pDialogWidget;
    }
private slots:
    void onAddHabitButtonClicked();
private:
    QWidget* mainWidget;

    void createDialog();
    void createHabit();
    QLabel* m_pGreetLabel;
    QPushButton* m_pAddHabitButton;
    myDialogWidget* m_pDialogWidget;
    QHBoxLayout* m_pGreetAndHabitHLayout;
    QVBoxLayout* m_pGHabitVLayout;
};

#endif // GREETWIDGETCLASS_H
