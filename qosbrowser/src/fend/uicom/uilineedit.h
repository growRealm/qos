#ifndef UILINEEDIT_H
#define UILINEEDIT_H

#include <QLineEdit>

class UiLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    UiLineEdit(QWidget* parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // UILINEEDIT_H
