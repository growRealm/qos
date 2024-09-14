#include "exceptions.h"
#include "globals.h"
#include "src/helper/filehelper.h"
#include <QDebug>



BaseException::BaseException(const QString &code, const QString &msg)
{
    m_code = code;
    m_msg = msg;
}

ErrorMap BaseException::parseErrorCode(const QString &csvPath)
{
    ErrorMap m_map;
    int sectionCount = 6;
    QList<QStringList> records = FileHelper::readAllCsv(csvPath);

    for(int i = 1; i < records.size(); i++) {
        auto record = records[i];
        QString code;
        QString msg;
        for (int j = 0; j < sectionCount; ++ j) {

            if (record[j] == "") {
                code += "0";
            }
            else {
                QStringList strs = record[j].split("_");
                msg += strs[0];
                code += strs[1];
            }
        }
        if (record[sectionCount] != "") {
            msg = record[sectionCount];
        }
        m_map[code] = msg;
    }
    return m_map;
}

void BaseException::generateErrorCodeHFile(const QString &csvPath, const QString& targetPath)
{
    QStringList rows;
    rows << "#ifndef ERRORCODE_H" << "#define ERRORCODE_H\n\n";

    ErrorMap errors = parseErrorCode(csvPath);
    ErrorMap::const_iterator iter = errors.constBegin();
    while (iter != errors.constEnd()) {
        rows << QString("#define EC_%1 \"%1\"  // %2").arg(iter.key(), iter.value());
        ++iter;
    }
    rows << "\n\n#endif // ERRORCODE_H";
    FileHelper::writeFlie(rows, targetPath);
}

QString BaseException::msg() const
{
    static ErrorMap m_map = BaseException::parseErrorCode(GLOBAL::PATH::ERROR_CODE_PATH);
    QString m = QString("错误(%1): %2").arg(m_code, m_map[m_code]);
    if  (m_msg != "") {
        m += QString("，详情: %1").arg(m_msg);
    }
    return m;
}

QString BaseException::code() const
{
    return m_code;
}
