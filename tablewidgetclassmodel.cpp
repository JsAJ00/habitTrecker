#include "tablewidgetclassmodel.h"

TableWidgetClassModel::TableWidgetClassModel(QAbstractTableModel *parent)
    : QAbstractTableModel{parent}
{
    //resizing habitData under Bools vector
    habitData.resize(0, QVector<bool>(7, false));
}

//getters
int TableWidgetClassModel::rowCount(const QModelIndex &) const
{
    return habits.size();
}

int TableWidgetClassModel::columnCount(const QModelIndex &) const
{
    return 7;
}


//data view settings
QVariant TableWidgetClassModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Qt::DisplayRole:
    case Qt::CheckStateRole:
        return habitData[index.row()][index.column()] ? Qt::Checked : Qt::Unchecked;

    case Qt::BackgroundRole:
        if (MyColor != "none") {
            if (MyColor == "red") {
                return QBrush(Qt::red);
            } else if (MyColor == "green") {
                return QBrush(Qt::green);
            }
        }
        return QBrush(Qt::blue);

    case Qt::FontRole: {
        QFont boldFont(":/new/fonts/resources/RobotoMono-Italic-VariableFont_wght.ttf");
        boldFont.setBold(true);
        return boldFont;
    }

    default:
        return QVariant();
    }
}



//Headers data view settings
QVariant TableWidgetClassModel::headerData(int section, Qt::Orientation orientation, int role) const {
    switch (orientation) {
    case Qt::Horizontal:
        switch (role) {
        case Qt::ForegroundRole:
            return QBrush(section % 2 == 0 ? Qt::red : Qt::white);

        case Qt::BackgroundRole:
            return QBrush(Qt::green);

        case Qt::DisplayRole: {
            QStringList days = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
            return days[section];
        }

        default:
            return QVariant();
        }

    case Qt::Vertical:
        switch (role) {
        case Qt::SizeHintRole:
            return QSize(100, 135);

        case Qt::DisplayRole:
            return habits[section];

        default:
            return QVariant();
        }

    default:
        return QVariant();
    }
}


//change color of cell
bool TableWidgetClassModel::setData(const QModelIndex &index, const QString& color, int role)
{
    if(role == Qt::UserRole){
        MyColor = color;
        emit dataChanged(index, index, {Qt::BackgroundRole});
        return true;
    }
    return false;
}


//Adding habits
void TableWidgetClassModel::addHabit(const QString &habit, const QVector<int> &days)
{
    beginInsertRows(QModelIndex(), habits.size(), habits.size());
    habits.append(habit);
    habitData.resize(habits.size());
    habitData.last().resize(7, false);
    for(int day : days){
        habitData.last()[day] = true;
    }
    endInsertRows();
}

