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
    myDialogWidget* getMyDialog();

private slots:
    void onAddHabitButtonClicked();
private:
    QWidget* mainWidget;
    myDialogWidget* m_pDialogWidget;

    QLabel* m_pGreetLabel;
    QPushButton* m_pAddHabitButton;

    QHBoxLayout* m_pGreetAndHabitHLayout;
    QVBoxLayout* m_pGHabitVLayout;

    void createHabit();
};

#endif // GREETWIDGETCLASS_H
