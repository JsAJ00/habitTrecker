#ifndef TABLEDELIGATECLASS_H
#define TABLEDELIGATECLASS_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>

class tableDeligateClass : public QStyledItemDelegate
{
public:
    tableDeligateClass(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // TABLEDELIGATECLASS_H
