#include "uicompletercombobox.h"

UiCompleterComboBox::UiCompleterComboBox(QWidget *parent) : QComboBox(parent) {
    // 设置下拉框的样式
        setStyleSheet("QComboBox { background-color: #f0f0f0; }");
    // 设置下拉框的item样式
        setItemDelegate(new UiCompleterComboBox::CompleterItemDelegate());
}
