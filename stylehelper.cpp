#include "stylehelper.h"

QString stylehelper::getAddButtonStyle()
{
    return "QPushButton{"
           "    color: #e5ffff;"
           "    background-color: #424242;"
           "    font-family: 'Roboto Mono';"
           "    font-size: 20px;"
           "    border-radius: 5px;"
           "}"
           ""
           "QPushButton::hover{"
           "    background-color: #605638;"
           "}"
           ""
           "QPushButton::pressed{"
           "    background-color: #605638;"
           "}";
}

QString stylehelper::getHabitTasksLabelStyle()
{
    return "QLabel{"
            "  color: #e5ffff;"
            "  background-color: #424242;"
            "  font-family: 'Roboto Mono';"
            "  font-size: 30px;"
            "}";
}

QString stylehelper::getTableStyle()
{
    return "QTableWidget{"
           "    color: red;"
           "}";
}

QString stylehelper::getHeaderTableStyle()
{
    return "";
}
