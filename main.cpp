#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Habit Tracker");
    w.setFixedSize(1500,800);
    w.show();
    return a.exec();
}
