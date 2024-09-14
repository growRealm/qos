#ifndef DBSQLITE_H
#define DBSQLITE_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

typedef QMap<QString, QVariant> RECORD;

class DbSqlite
{
public:
    DbSqlite();
    ~DbSqlite();

    void connect(const QString& dbPath);
    QSqlQuery exec(const QString& sql);
    QSqlQuery exec(const QString& sql, const QVariantList &variantList);
    bool exists(const QString& sql);
    QList<RECORD> select(const QString &sql);

private:
    QSqlDatabase m_db;
};

#endif // DBSQLITE_H
