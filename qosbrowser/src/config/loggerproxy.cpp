#include "loggerproxy.h"
#include "qthread.h"
#include "src/middle/manglobal.h"

/**
基础日志类，派生出该类来实现具体的日志记录
*/
LoggerProxy::LoggerProxy(QObject *parent)
    : QObject{parent}
{

}

LoggerProxy::~LoggerProxy()
{
    if (m_logger){
        delete m_logger;
        m_logger = nullptr;
    }
    qDebug("delete LoggerProxy ");
}

const LoggerProxy &LoggerProxy::reset(const QString &file, int line, const QString &func)
{
    m_file = file;
    m_line = line;
    m_func = func;
    return *this;
}

void LoggerProxy::total(const QVariant &var, bool up) const
{
    doLog(GLOBAL::LOG_LEVEL::TOTAL, var, up);
}

void LoggerProxy::debug(const QVariant &var, bool up) const
{
    doLog(GLOBAL::LOG_LEVEL::DEBUG, var, up);
}

void LoggerProxy::info(const QVariant &var, bool up) const
{
    doLog(GLOBAL::LOG_LEVEL::INFO, var, up);
}

void LoggerProxy::warning(const QVariant &var, bool up) const
{
    doLog(GLOBAL::LOG_LEVEL::WARNING, var, up);
}

void LoggerProxy::error(const QVariant &var, bool up) const
{
    doLog(GLOBAL::LOG_LEVEL::ERROR, var, up);
}

void LoggerProxy::fatal(const QVariant &var, bool up) const
{
    doLog(GLOBAL::LOG_LEVEL::FATAL, var, up);
}

void LoggerProxy::doLog(GLOBAL::LOG_LEVEL level, const QVariant &var, bool up) const
{
    if (!m_logger)
    {
        return;
    }

    if (level >= m_level)
        emit sigLog(m_file, m_line, m_func, QThread::currentThreadId(),
                    level, var, up);
}

void LoggerProxy::setLogger(BasicLogger *newLogger)
{
    if (!m_logger) {
        m_logger = newLogger;
        connect(this, &LoggerProxy::sigLog, m_logger, &BasicLogger::onLog);
    }
}

void LoggerProxy::setLevel(GLOBAL::LOG_LEVEL newLevel)
{
    m_level = newLevel;
}


