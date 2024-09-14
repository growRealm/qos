#include "uitableview.h"
#include <src/fend/uidelegates/uitableitemdelegate.h>

UiTableView::UiTableView(QWidget *parent):QTableView(parent)
{
    setItemDelegate(new UiTableItemDelegate(this));
}
