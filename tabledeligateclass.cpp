#include "tabledeligateclass.h"

class CustomDelegate : public QStyledItemDelegate
{
public:
    CustomDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        // Alternate row color
        if (option.state & QStyle::State_Active) {
            painter->fillRect(option.rect, QColor("#ff6347"));  // Selected item background color
        } else if (index.row() % 2 == 0) {
            painter->fillRect(option.rect, QColor("#f0f0f0"));  // Even row color
        } else {
            painter->fillRect(option.rect, QColor("#e0e0e0"));  // Odd row color
        }

        // Call the base class implementation for default painting
        QStyledItemDelegate::paint(painter, option, index);
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        return QStyledItemDelegate::sizeHint(option, index);
    }
};

