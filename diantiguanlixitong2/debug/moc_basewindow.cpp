/****************************************************************************
** Meta object code from reading C++ file 'basewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../basewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BaseWindow_t {
    QByteArrayData data[13];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseWindow_t qt_meta_stringdata_BaseWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BaseWindow"
QT_MOC_LITERAL(1, 11, 18), // "onButtonMinClicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 22), // "onButtonRestoreClicked"
QT_MOC_LITERAL(4, 54, 18), // "onButtonMaxClicked"
QT_MOC_LITERAL(5, 73, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(6, 94, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 116, 25), // "on_treeView_doubleClicked"
QT_MOC_LITERAL(8, 142, 5), // "index"
QT_MOC_LITERAL(9, 148, 23), // "on_treeview_datachanged"
QT_MOC_LITERAL(10, 172, 12), // "QVector<int>"
QT_MOC_LITERAL(11, 185, 20), // "onRadiobuttonClicked"
QT_MOC_LITERAL(12, 206, 16) // "QAbstractButton*"

    },
    "BaseWindow\0onButtonMinClicked\0\0"
    "onButtonRestoreClicked\0onButtonMaxClicked\0"
    "onButtonCloseClicked\0on_pushButton_clicked\0"
    "on_treeView_doubleClicked\0index\0"
    "on_treeview_datachanged\0QVector<int>\0"
    "onRadiobuttonClicked\0QAbstractButton*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    3,   62,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex, 0x80000000 | 10,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 12,    2,

       0        // eod
};

void BaseWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaseWindow *_t = static_cast<BaseWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonMinClicked(); break;
        case 1: _t->onButtonRestoreClicked(); break;
        case 2: _t->onButtonMaxClicked(); break;
        case 3: _t->onButtonCloseClicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_treeView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_treeview_datachanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3]))); break;
        case 7: _t->onRadiobuttonClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject BaseWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BaseWindow.data,
      qt_meta_data_BaseWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BaseWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BaseWindow.stringdata0))
        return static_cast<void*>(const_cast< BaseWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int BaseWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
