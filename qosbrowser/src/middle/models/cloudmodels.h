#ifndef CLOUDMODELS_H
#define CLOUDMODELS_H

#include <QString>
#include <QMetaType>

struct BaseObject {
    bool isValid() const {return !isInvalid();}
    bool isInvalid() const {return name.isNull() || name.isEmpty();}
    QString name;
};
Q_DECLARE_METATYPE(BaseObject);

struct MyBucket: public BaseObject
{
    MyBucket();
    QString location;
    QString createDate;
};
Q_DECLARE_METATYPE(MyBucket);

struct MyObject: public BaseObject
{
    bool isDir() const {return isValid() && name.endsWith("/");}
    bool isFile() const {return isValid() && !name.endsWith("/");}
    QString lastmodified;
    qulonglong size = 0;
    QString dir;
    QString key;
};
Q_DECLARE_METATYPE(MyObject);

#endif // CLOUDMODELS_H
