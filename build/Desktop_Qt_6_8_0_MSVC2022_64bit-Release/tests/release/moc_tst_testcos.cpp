/****************************************************************************
** Meta object code from reading C++ file 'tst_testcos.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tests/testcos/tst_testcos.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_testcos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTestCosENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTestCosENDCLASS = QtMocHelpers::stringData(
    "TestCos",
    "initTestCase",
    "",
    "cleanupTestCase",
    "test_buckets",
    "test_isBucketExists",
    "test_getBucketLocation",
    "test_putBucket",
    "test_deleteBucket",
    "test_getObjects",
    "test_getObjects2_data",
    "test_getObjects2",
    "test_getObjectError",
    "test_putObject",
    "test_getObject"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTestCosENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    0,   95,    2, 0x08,    4 /* Private */,
       6,    0,   96,    2, 0x08,    5 /* Private */,
       7,    0,   97,    2, 0x08,    6 /* Private */,
       8,    0,   98,    2, 0x08,    7 /* Private */,
       9,    0,   99,    2, 0x08,    8 /* Private */,
      10,    0,  100,    2, 0x08,    9 /* Private */,
      11,    0,  101,    2, 0x08,   10 /* Private */,
      12,    0,  102,    2, 0x08,   11 /* Private */,
      13,    0,  103,    2, 0x08,   12 /* Private */,
      14,    0,  104,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TestCos::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTestCosENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTestCosENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTestCosENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TestCos, std::true_type>,
        // method 'initTestCase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cleanupTestCase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_buckets'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_isBucketExists'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_getBucketLocation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_putBucket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_deleteBucket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_getObjects'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_getObjects2_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_getObjects2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_getObjectError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_putObject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'test_getObject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TestCos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestCos *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->cleanupTestCase(); break;
        case 2: _t->test_buckets(); break;
        case 3: _t->test_isBucketExists(); break;
        case 4: _t->test_getBucketLocation(); break;
        case 5: _t->test_putBucket(); break;
        case 6: _t->test_deleteBucket(); break;
        case 7: _t->test_getObjects(); break;
        case 8: _t->test_getObjects2_data(); break;
        case 9: _t->test_getObjects2(); break;
        case 10: _t->test_getObjectError(); break;
        case 11: _t->test_putObject(); break;
        case 12: _t->test_getObject(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *TestCos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestCos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTestCosENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestCos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
