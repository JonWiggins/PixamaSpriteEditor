/****************************************************************************
** Meta object code from reading C++ file 'pixamamodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pixamamodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pixamamodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PixamaModel_t {
    QByteArrayData data[32];
    char stringdata0[388];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PixamaModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PixamaModel_t qt_meta_stringdata_PixamaModel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PixamaModel"
QT_MOC_LITERAL(1, 12, 11), // "imageSignal"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "image"
QT_MOC_LITERAL(4, 31, 25), // "displayErrorMessageSignal"
QT_MOC_LITERAL(5, 57, 5), // "title"
QT_MOC_LITERAL(6, 63, 7), // "details"
QT_MOC_LITERAL(7, 71, 16), // "frameStateSignal"
QT_MOC_LITERAL(8, 88, 16), // "std::vector<int>"
QT_MOC_LITERAL(9, 105, 10), // "frameState"
QT_MOC_LITERAL(10, 116, 15), // "playFrameSignal"
QT_MOC_LITERAL(11, 132, 5), // "frame"
QT_MOC_LITERAL(12, 138, 14), // "mouseEventSlot"
QT_MOC_LITERAL(13, 153, 1), // "x"
QT_MOC_LITERAL(14, 155, 1), // "y"
QT_MOC_LITERAL(15, 157, 12), // "saveFileSlot"
QT_MOC_LITERAL(16, 170, 8), // "fileName"
QT_MOC_LITERAL(17, 179, 12), // "openFileSlot"
QT_MOC_LITERAL(18, 192, 8), // "filename"
QT_MOC_LITERAL(19, 201, 12), // "newFrameSlot"
QT_MOC_LITERAL(20, 214, 13), // "copyFrameSlot"
QT_MOC_LITERAL(21, 228, 15), // "colorChangeSlot"
QT_MOC_LITERAL(22, 244, 27), // "std::tuple<int,int,int,int>"
QT_MOC_LITERAL(23, 272, 5), // "color"
QT_MOC_LITERAL(24, 278, 14), // "toolSelectSlot"
QT_MOC_LITERAL(25, 293, 4), // "tool"
QT_MOC_LITERAL(26, 298, 15), // "exportAsPNGSlot"
QT_MOC_LITERAL(27, 314, 15), // "exportAsJPGSlot"
QT_MOC_LITERAL(28, 330, 20), // "exportFrameAsGIFSlot"
QT_MOC_LITERAL(29, 351, 15), // "selectFrameSlot"
QT_MOC_LITERAL(30, 367, 11), // "frameNumber"
QT_MOC_LITERAL(31, 379, 8) // "playSlot"

    },
    "PixamaModel\0imageSignal\0\0image\0"
    "displayErrorMessageSignal\0title\0details\0"
    "frameStateSignal\0std::vector<int>\0"
    "frameState\0playFrameSignal\0frame\0"
    "mouseEventSlot\0x\0y\0saveFileSlot\0"
    "fileName\0openFileSlot\0filename\0"
    "newFrameSlot\0copyFrameSlot\0colorChangeSlot\0"
    "std::tuple<int,int,int,int>\0color\0"
    "toolSelectSlot\0tool\0exportAsPNGSlot\0"
    "exportAsJPGSlot\0exportFrameAsGIFSlot\0"
    "selectFrameSlot\0frameNumber\0playSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PixamaModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    2,   97,    2, 0x06 /* Public */,
       7,    1,  102,    2, 0x06 /* Public */,
      10,    1,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,  108,    2, 0x0a /* Public */,
      15,    1,  113,    2, 0x0a /* Public */,
      17,    1,  116,    2, 0x0a /* Public */,
      19,    0,  119,    2, 0x0a /* Public */,
      20,    0,  120,    2, 0x0a /* Public */,
      21,    1,  121,    2, 0x0a /* Public */,
      24,    1,  124,    2, 0x0a /* Public */,
      26,    1,  127,    2, 0x0a /* Public */,
      27,    1,  130,    2, 0x0a /* Public */,
      28,    1,  133,    2, 0x0a /* Public */,
      29,    1,  136,    2, 0x0a /* Public */,
      31,    0,  139,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QImage,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,

       0        // eod
};

void PixamaModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PixamaModel *_t = static_cast<PixamaModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageSignal((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->displayErrorMessageSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->frameStateSignal((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 3: _t->playFrameSignal((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->mouseEventSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->saveFileSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->openFileSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->newFrameSlot(); break;
        case 8: _t->copyFrameSlot(); break;
        case 9: _t->colorChangeSlot((*reinterpret_cast< std::tuple<int,int,int,int>(*)>(_a[1]))); break;
        case 10: _t->toolSelectSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->exportAsPNGSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->exportAsJPGSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->exportFrameAsGIFSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->selectFrameSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->playSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PixamaModel::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaModel::imageSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PixamaModel::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaModel::displayErrorMessageSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PixamaModel::*)(std::vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaModel::frameStateSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PixamaModel::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaModel::playFrameSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PixamaModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PixamaModel.data,
      qt_meta_data_PixamaModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PixamaModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PixamaModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PixamaModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PixamaModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void PixamaModel::imageSignal(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PixamaModel::displayErrorMessageSignal(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PixamaModel::frameStateSignal(std::vector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PixamaModel::playFrameSignal(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
