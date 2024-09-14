#ifndef UIPUSHBUTTON_H
#define UIPUSHBUTTON_H

#include <QPushButton>

class UiPushButton : public QPushButton
{
    Q_OBJECT
public:
    UiPushButton(QWidget* parent=nullptr);

protected:
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
};

#endif // UIPUSHBUTTON_H
