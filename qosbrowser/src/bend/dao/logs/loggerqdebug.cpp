#include "loggerqdebug.h"
#include "src/config/globals.h"
#include <QThread>
#include <QDebug>
#include <QDateTime>
#include <iostream>

LoggerQDebug::LoggerQDebug(QObject *parent): BasicLogger(parent)
{
    qInstallMessageHandler(handle);
}

LoggerQDebug::~LoggerQDebug()
{

}

void LoggerQDebug::print(const QString &file, int line, const QString &func, void* tid,
                         int level, const QVariant &var, bool up)
{
    QDateTime dt;
    QString dtStr = dt.currentDateTime().toString(Qt::ISODate);
    QString front = QString("%1[%2] %3:%4 -")
                        .arg(dtStr, GLOBAL::LOG_NAMES[level], file)
                        .arg(line);
    front = front.replace("..\\", "");
    qDebug() << front.toLocal8Bit().data() << var;  // 使用qDebug而不是直接存文件，是为了打印QVariant类型
}

void LoggerQDebug::handle(QtMsgType , const QMessageLogContext& context , const QString& msg)
{
    QFile file(filePath());

    QString key("QVariant(");
    QString message = msg;
    if (msg.indexOf(key) != -1) {
        message.replace(msg.indexOf(key), key.size(), "").chop(1);
    }

    if (file.open(QIODevice::WriteOnly|QIODevice::Append))
    {
        // 输入到文件流中
        QTextStream stream(&file);
        stream << message << Qt::endl;
        file.close();
    }
    // 用于控制台输出
    std::cout << message.toUtf8().data() << std::endl;
}
