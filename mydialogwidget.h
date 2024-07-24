#ifndef MYDIALOGWIDGET_H
#define MYDIALOGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>


class myDialogWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myDialogWidget(QWidget *parent = nullptr);
    QString getTextFromLineEdit();

private slots:
    void onAddClicked();
signals:
    void mySignal();
private:
    QString text;
    QLineEdit* m_pLineEdit;
    QPushButton* m_pPushButton;

    QHBoxLayout* mainHLayout;
};

#endif // MYDIALOGWIDGET_H
