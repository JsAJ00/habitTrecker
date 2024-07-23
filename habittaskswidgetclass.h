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
    QPushButton* getCompleteButton(){
        return completeBtn;
    }
    void changeBackGround(QString color){
        setStyleSheet("background-color: " + color);
    };
signals:
    void DeleteHabitSignal(HabitTasksWidgetClass*);
    void CompleteHabitSignal(HabitTasksWidgetClass*);
private slots:
    void onCompleteBtnClicked();
    void ondeleteBtnClicked();

private:
    QString& name;
    QVBoxLayout* myVLayout;
    QHBoxLayout* myHLayout;

    QLabel* lbl;
    QPushButton* deleteBtn;
    QPushButton* completeBtn;
};

#endif // HABITTASKSWIDGETCLASS_H
