#include "tablewidgetclassmodel.h"

TableWidgetClassModel::TableWidgetClassModel(QAbstractTableModel *parent)
    : QAbstractTableModel{parent}
{
    habitData.resize(0, QVector<bool>(7, false));

}

int TableWidgetClassModel::rowCount(const QModelIndex &) const
{
    return habits.size();
}

int TableWidgetClassModel::columnCount(const QModelIndex &) const
{
    return 7;
}

QVariant TableWidgetClassModel::data(const QModelIndex &index, int role) const
{
    switch(role){
    case Qt::DisplayRole:
        return habitData[index.row()][index.column()] ? Qt::Checked : Qt::Unchecked;
    case Qt::CheckStateRole:
        return habitData[index.row()][index.column()] ? Qt::Checked : Qt::Unchecked;
    case Qt::BackgroundRole:
        if(isCollored(index)){
            return QBrush(Qt::green);
        }else{
            return QBrush(Qt::blue);
        }
    case Qt::FontRole:
        QFont boldFont(":/new/fonts/resources/RobotoMono-Italic-VariableFont_wght.ttf");
        boldFont.setBold(true);
        return boldFont;
    }
    return QVariant();
}

QVariant TableWidgetClassModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal) {
        if (role == Qt::ForegroundRole) {
            if (section % 2 == 0)
                return QBrush(Qt::red);
            else
                return QBrush(Qt::white);
        }
        else if (role == Qt::BackgroundRole) {
            return QBrush(Qt::green);
        }
    }
    if (orientation == Qt::Vertical){
        if (role == Qt::SizeHintRole){
            return QSize(100,135);
        }
    }


    if(role == Qt::DisplayRole){
        //setting data
        if(orientation == Qt::Horizontal){
            QStringList days = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
            return days[section];

        }else if(orientation == Qt::Vertical){
            return habits[section];
        }

    }
    return QVariant();
}


bool TableWidgetClassModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::UserRole){
        habitData[index.row()][index.column()] = value.toBool();
        emit dataChanged(index, index, {Qt::BackgroundRole});
        return true;
    }
    return false;
}


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
//sadg
void TableWidgetClassModel::deleteHabit(const int index)
{
    beginRemoveRows(QModelIndex(), 0, 0);
    habits.remove(index);
    endRemoveRows();
}



