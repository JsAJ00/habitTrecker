#ifndef TABLEWIDGETCLASSMODEL_H
#define TABLEWIDGETCLASSMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QStringList>
#include <QTableView>
#include <QTableView>
#include <QFontDatabase>

class TableWidgetClassModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableWidgetClassModel(QAbstractTableModel *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)const override;
    bool setData(const QModelIndex& index, const QString& color, int role = Qt::EditRole);

    void addHabit(const QString &habit, const QVector<int> &days);
    void deleteHabit(const int index);

private:
    QStringList habits;
    QVector<QVector<bool>> habitData;

    QString MyColor = "none";
};

#endif // TABLEWIDGETCLASSMODEL_H
