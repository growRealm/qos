#include <QApplication>

#include "manglobal.h"
#include "src/bend/gateway.h"
#include "src/middle/manmodels.h"
#include "src/middle/signals/mansignals.h"
#include "src/plugins/manplugin.h"

#include <src/bend/man/mancloud.h>
#include <src/bend/man/mandb.h>

Q_GLOBAL_STATIC(ManGlobal, ins)

ManGlobal::ManGlobal(QObject *parent)
    : QObject{parent}
{
    mLog = new LoggerProxy(this);
    mCloud = new ManCloud(this);
    mDb = new ManDB(this);
    mSignal = new ManSignals(this);
    mPlugin = new ManPlugin(this);
    mGate = new GateWay(this);
//    mModels = new ManModels(this);
}

ManGlobal::~ManGlobal()
{
    qDebug("delete ManGlobal ");
}

ManGlobal *ManGlobal::instance()
{
    return ins();
}

void ManGlobal::init(int argc, char *argv[])
{
    mModels = new ManModels(this);
    FileHelper::mkPath(GLOBAL::PATH::LOG_DIR);
    FileHelper::mkPath(GLOBAL::PATH::TMP);

    mPlugin->installPlugins(argc, argv);

    QString qssStr = FileHelper::readAllTxt(":/static/qss/default.qss");
    qApp->setStyleSheet(qssStr);

    mDb->init();
}
