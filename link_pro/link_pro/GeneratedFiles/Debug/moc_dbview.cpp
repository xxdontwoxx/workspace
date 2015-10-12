/****************************************************************************
** Meta object code from reading C++ file 'dbview.h'
**
** Created: Mon Oct 12 14:12:18 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dbview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DBView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,    8,    7,    7, 0x0a,
      82,    7,    7,    7, 0x0a,
     107,    7,    7,    7, 0x0a,
     134,  128,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DBView[] = {
    "DBView\0\0current,previous\0"
    "on_currentItemChanged(QListWidgetItem*,QListWidgetItem*)\0"
    "closeEvent(QCloseEvent*)\0on_actions(QAction*)\0"
    "index\0on_tableview_doubleclick(QModelIndex)\0"
};

void DBView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DBView *_t = static_cast<DBView *>(_o);
        switch (_id) {
        case 0: _t->on_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 2: _t->on_actions((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->on_tableview_doubleclick((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DBView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DBView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DBView,
      qt_meta_data_DBView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DBView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DBView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DBView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DBView))
        return static_cast<void*>(const_cast< DBView*>(this));
    return QWidget::qt_metacast(_clname);
}

int DBView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
