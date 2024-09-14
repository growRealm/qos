#ifndef UITOOLBARWIDGET_H
#define UITOOLBARWIDGET_H

#include <QWidget>

namespace Ui {
class UiToolBarWidget;
}

class UiToolBarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UiToolBarWidget(QWidget *parent = nullptr);
    ~UiToolBarWidget();

private slots:
    void on_btnQuit_clicked();

private:
    Ui::UiToolBarWidget *ui;
};

#endif // UITOOLBARWIDGET_H
