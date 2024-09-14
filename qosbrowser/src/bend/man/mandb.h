#ifndef MANDB_H
#define MANDB_H

#include <QObject>
#include <src/helper/dbsqlite.h>
#include <src/bend/dao/dbs/daologininfosqlite.h>


class ManDB : public QObject
{
    Q_OBJECT
public:
    explicit ManDB(QObject *parent = nullptr);
    ~ManDB();

    void init();

    void saveLoginInfo(const QString& name, const QString& id, const QString& key, const QString& remark);
    void removeLoginInfo(const QString& id);
    int indexOfLoginInfo(const QString& secretId);
    QStringList loginNameList();
    LoginInfo loginInfoByName(const QString& name);

private:
    DaoLoginInfoSqlite m_daoLoginInfo;
    QList<LoginInfo> m_loginInfoList;
};

#endif // MANDB_H
