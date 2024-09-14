#ifndef LOGGERQDEBUG_H
#define LOGGERQDEBUG_H
#include <QObject>
#include "basiclogger.h"


class LoggerQDebug : public BasicLogger
{
    Q_OBJECT
public:
    explicit LoggerQDebug(QObject *parent = nullptr);
    ~LoggerQDebug();

protected:
    virtual void print(const QString& file, int line, const QString& func, void* tid,
                       int level, const QVariant& var, bool up);

private:
    static void handle(QtMsgType type, const QMessageLogContext &contex, const QString &msg);
    QThread* m_td = nullptr;
};


#endif // LOGGERQDEBUG_H
