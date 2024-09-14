#ifndef MANGLOBAL_H
#define MANGLOBAL_H

#include <QObject>
#include "src/config/loggerproxy.h"
#include "src/config/errorcode.h"
#include "src/config/exceptions.h"

#define MG ManGlobal::instance()
#define mLogIns MG->mLog
#define mTotle mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).total
#define mDebug mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).debug
#define mInfo mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).info
#define mWarning mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).warning
#define mError mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).error
#define mFatal mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).fatal

// 不能将其它单例类的头文件放在全局单例的头文件中
// 具体哪个类引用，则哪个类再包含
// 使用对象树所属关系系统进行内存释放
class ManCloud;
class ManDB;
class ManPlugin;
class GateWay;
class ManSignals;
class LoggerProxy;
class ManModels;

class ManGlobal : public QObject
{
    Q_OBJECT
public:
    explicit ManGlobal(QObject *parent = nullptr);
    ~ManGlobal();
    static ManGlobal* instance();
    void init(int argc, char *argv[]);

public:
    LoggerProxy* mLog = nullptr;
    ManCloud* mCloud = nullptr;
    ManDB* mDb = nullptr;
    ManPlugin* mPlugin = nullptr;
    GateWay* mGate = nullptr;
    ManSignals* mSignal = nullptr;
    ManModels* mModels = nullptr;
};

#endif // MANGLOBAL_H
