#include "stylehelper.h"

QString stylehelper::getAddButtonStyle()
{
    return "QPushButton{"
           "    background-color: black;"
           "    border: none;"
           "    border-radius: 5px;"
           "}"
           ""
           "QPushButton::hover{"
           "    background-color: grey;"
           "}"
           ""
           "QPushButton::pressed{"
           "    background-color: red;"
           "}";
}
