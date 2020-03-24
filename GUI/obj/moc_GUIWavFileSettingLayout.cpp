/****************************************************************************
** Meta object code from reading C++ file 'GUIWavFileSettingLayout.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/settingWindow/layout/GUIWavFileSettingLayout.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUIWavFileSettingLayout.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GUIWavFileSettingLayout[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x08,
      39,   24,   24,   24, 0x08,
      55,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GUIWavFileSettingLayout[] = {
    "GUIWavFileSettingLayout\0\0loadWavFile()\0"
    "removeWavFile()\0clearWavFile()\0"
};

void GUIWavFileSettingLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GUIWavFileSettingLayout *_t = static_cast<GUIWavFileSettingLayout *>(_o);
        switch (_id) {
        case 0: _t->loadWavFile(); break;
        case 1: _t->removeWavFile(); break;
        case 2: _t->clearWavFile(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GUIWavFileSettingLayout::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GUIWavFileSettingLayout::staticMetaObject = {
    { &QGridLayout::staticMetaObject, qt_meta_stringdata_GUIWavFileSettingLayout,
      qt_meta_data_GUIWavFileSettingLayout, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GUIWavFileSettingLayout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GUIWavFileSettingLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GUIWavFileSettingLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GUIWavFileSettingLayout))
        return static_cast<void*>(const_cast< GUIWavFileSettingLayout*>(this));
    if (!strcmp(_clname, "GUISettingLayout"))
        return static_cast< GUISettingLayout*>(const_cast< GUIWavFileSettingLayout*>(this));
    return QGridLayout::qt_metacast(_clname);
}

int GUIWavFileSettingLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGridLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
