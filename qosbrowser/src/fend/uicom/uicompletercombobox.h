#ifndef UICOMPLETERCOMBOBOX_H
#define UICOMPLETERCOMBOBOX_H

#include <QComboBox>
#include <QPainter>
#include <QStyledItemDelegate>

class UiCompleterComboBox : public QComboBox
{
    Q_OBJECT
public:
    UiCompleterComboBox(QWidget *parent = nullptr);

private:
    class CompleterItemDelegate : public QStyledItemDelegate {
    public:
        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
            // 自定义item的绘制样式
            painter->save();
            painter->setPen(QPen(Qt::black, 1, Qt::SolidLine));
            painter->drawText(option.rect, Qt::AlignCenter, index.data().toString());
            painter->restore();
        }
    };
};

#endif // UICOMPLETERCOMBOBOX_H
