#include "src/fend/uilogin/uilogindialog.h"
#include "src/fend/uimain/uimain.h"
#include "src/middle/manglobal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MG->init(argc, argv);
    UiMain w;
    UiLoginDialog login;
    login.show();
    return a.exec();
}
