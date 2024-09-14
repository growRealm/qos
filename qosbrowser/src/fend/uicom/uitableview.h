#ifndef UITABLEVIEW_H
#define UITABLEVIEW_H

#include <QTableView>

class UiTableView : public QTableView
{
    Q_OBJECT
public:
    UiTableView(QWidget* parent=nullptr);
};

#endif // UITABLEVIEW_H
