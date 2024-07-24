#ifndef HABITTASKSWIDGETCLASS_H
#define HABITTASKSWIDGETCLASS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>


class HabitTasksWidgetClass : public QWidget
{
    Q_OBJECT
public:
    explicit HabitTasksWidgetClass(QString& name, QWidget *parent = nullptr);

signals:
    void DeleteHabitSignal(HabitTasksWidgetClass*);
    void CompleteHabitSignal(HabitTasksWidgetClass*);
private slots:
    void onCompleteBtnClicked();
    void ondeleteBtnClicked();

private:
    QLabel* lbl;
    QPushButton* deleteBtn;
    QPushButton* completeBtn;

    QVBoxLayout* myVLayout;
    QHBoxLayout* myHLayout;

    QString name;
};

#endif // HABITTASKSWIDGETCLASS_H
