#include "basiclogger.h"
#include "src/config/globals.h"
#include <QThread>
#include <QDir>
#include <QDate>
#include <QDebug>

/**
基础日志类，派生出该类来实现具体的日志记录
*/
BasicLogger::BasicLogger(QObject *parent)
{
    m_td = new QThread();
    moveToThread(m_td);
    m_td->start();
}

BasicLogger::~BasicLogger()
{
    if (m_td->isRunning())
    {
        m_td->quit();
        if (m_td->wait(1000))
        {
            m_td->terminate();
            m_td->wait(1000);
        }
    }
    delete m_td;
}

void BasicLogger::onLog(const QString& file, int line, const QString& func, void* tid,
                        int level, const QVariant &var, bool up)
{
    print(file, line, func, tid, level, var, up);
}

QString BasicLogger::filePath()
{
    QString name = QDate::currentDate().toString(Qt::ISODate);
    return FileHelper::joinPath(GLOBAL::PATH::LOG_DIR, QString("%1.log").arg(name));
}
