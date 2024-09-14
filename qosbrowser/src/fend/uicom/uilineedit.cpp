#include "uilineedit.h"

#include <QKeyEvent>

UiLineEdit::UiLineEdit(QWidget *parent):
    QLineEdit(parent)
{

}

void UiLineEdit::keyPressEvent(QKeyEvent *event)
{
    // 捕获ctrl+c和ctrl+v
    if (event->modifiers() == Qt::ControlModifier)
    {
        if (event->key() == Qt::Key_C || event->key() == Qt::Key_V)
        {
            return;
        }
    }
    QLineEdit::keyPressEvent(event);
}
