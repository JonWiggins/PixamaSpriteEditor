/****************************************************************************
** Meta object code from reading C++ file 'pixamawindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pixamawindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pixamawindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PixamaWindow_t {
    QByteArrayData data[45];
    char stringdata0[734];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PixamaWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PixamaWindow_t qt_meta_stringdata_PixamaWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PixamaWindow"
QT_MOC_LITERAL(1, 13, 16), // "mouseClickSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 1), // "x"
QT_MOC_LITERAL(4, 33, 1), // "y"
QT_MOC_LITERAL(5, 35, 17), // "colorButtonSignal"
QT_MOC_LITERAL(6, 53, 27), // "std::tuple<int,int,int,int>"
QT_MOC_LITERAL(7, 81, 5), // "color"
QT_MOC_LITERAL(8, 87, 10), // "toolSelect"
QT_MOC_LITERAL(9, 98, 4), // "tool"
QT_MOC_LITERAL(10, 103, 14), // "saveFileSignal"
QT_MOC_LITERAL(11, 118, 8), // "fileName"
QT_MOC_LITERAL(12, 127, 14), // "openFileSignal"
QT_MOC_LITERAL(13, 142, 17), // "exportAsPNGSignal"
QT_MOC_LITERAL(14, 160, 17), // "exportAsJPGSignal"
QT_MOC_LITERAL(15, 178, 22), // "exportFrameAsGIFSignal"
QT_MOC_LITERAL(16, 201, 14), // "newFrameSignal"
QT_MOC_LITERAL(17, 216, 15), // "copyFrameSignal"
QT_MOC_LITERAL(18, 232, 17), // "selectFrameSignal"
QT_MOC_LITERAL(19, 250, 11), // "frameNumber"
QT_MOC_LITERAL(20, 262, 10), // "playSignal"
QT_MOC_LITERAL(21, 273, 23), // "displayErrorMessageSlot"
QT_MOC_LITERAL(22, 297, 5), // "title"
QT_MOC_LITERAL(23, 303, 7), // "details"
QT_MOC_LITERAL(24, 311, 15), // "updateImageSlot"
QT_MOC_LITERAL(25, 327, 5), // "image"
QT_MOC_LITERAL(26, 333, 21), // "updateFrameSelectSlot"
QT_MOC_LITERAL(27, 355, 16), // "std::vector<int>"
QT_MOC_LITERAL(28, 372, 10), // "frameState"
QT_MOC_LITERAL(29, 383, 13), // "playFrameSlot"
QT_MOC_LITERAL(30, 397, 23), // "on_resizeButton_clicked"
QT_MOC_LITERAL(31, 421, 21), // "on_copyButton_clicked"
QT_MOC_LITERAL(32, 443, 16), // "on_color_clicked"
QT_MOC_LITERAL(33, 460, 22), // "on_eraseButton_clicked"
QT_MOC_LITERAL(34, 483, 21), // "on_drawButton_clicked"
QT_MOC_LITERAL(35, 505, 23), // "on_bucketButton_clicked"
QT_MOC_LITERAL(36, 529, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(37, 553, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(38, 577, 25), // "on_newFrameButton_clicked"
QT_MOC_LITERAL(39, 603, 34), // "on_frameSelectSpinBox_valueCh..."
QT_MOC_LITERAL(40, 638, 4), // "arg1"
QT_MOC_LITERAL(41, 643, 22), // "on_actionGIF_triggered"
QT_MOC_LITERAL(42, 666, 22), // "on_actionPNG_triggered"
QT_MOC_LITERAL(43, 689, 22), // "on_actionJPG_triggered"
QT_MOC_LITERAL(44, 712, 21) // "on_playButton_clicked"

    },
    "PixamaWindow\0mouseClickSignal\0\0x\0y\0"
    "colorButtonSignal\0std::tuple<int,int,int,int>\0"
    "color\0toolSelect\0tool\0saveFileSignal\0"
    "fileName\0openFileSignal\0exportAsPNGSignal\0"
    "exportAsJPGSignal\0exportFrameAsGIFSignal\0"
    "newFrameSignal\0copyFrameSignal\0"
    "selectFrameSignal\0frameNumber\0playSignal\0"
    "displayErrorMessageSlot\0title\0details\0"
    "updateImageSlot\0image\0updateFrameSelectSlot\0"
    "std::vector<int>\0frameState\0playFrameSlot\0"
    "on_resizeButton_clicked\0on_copyButton_clicked\0"
    "on_color_clicked\0on_eraseButton_clicked\0"
    "on_drawButton_clicked\0on_bucketButton_clicked\0"
    "on_actionSave_triggered\0on_actionOpen_triggered\0"
    "on_newFrameButton_clicked\0"
    "on_frameSelectSpinBox_valueChanged\0"
    "arg1\0on_actionGIF_triggered\0"
    "on_actionPNG_triggered\0on_actionJPG_triggered\0"
    "on_playButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PixamaWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  164,    2, 0x06 /* Public */,
       5,    1,  169,    2, 0x06 /* Public */,
       8,    1,  172,    2, 0x06 /* Public */,
      10,    1,  175,    2, 0x06 /* Public */,
      12,    1,  178,    2, 0x06 /* Public */,
      13,    1,  181,    2, 0x06 /* Public */,
      14,    1,  184,    2, 0x06 /* Public */,
      15,    1,  187,    2, 0x06 /* Public */,
      16,    0,  190,    2, 0x06 /* Public */,
      17,    0,  191,    2, 0x06 /* Public */,
      18,    1,  192,    2, 0x06 /* Public */,
      20,    0,  195,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    2,  196,    2, 0x0a /* Public */,
      24,    1,  201,    2, 0x0a /* Public */,
      26,    1,  204,    2, 0x0a /* Public */,
      29,    1,  207,    2, 0x0a /* Public */,
      30,    0,  210,    2, 0x08 /* Private */,
      31,    0,  211,    2, 0x08 /* Private */,
      32,    0,  212,    2, 0x08 /* Private */,
      33,    0,  213,    2, 0x08 /* Private */,
      34,    0,  214,    2, 0x08 /* Private */,
      35,    0,  215,    2, 0x08 /* Private */,
      36,    0,  216,    2, 0x08 /* Private */,
      37,    0,  217,    2, 0x08 /* Private */,
      38,    0,  218,    2, 0x08 /* Private */,
      39,    1,  219,    2, 0x08 /* Private */,
      41,    0,  222,    2, 0x08 /* Private */,
      42,    0,  223,    2, 0x08 /* Private */,
      43,    0,  224,    2, 0x08 /* Private */,
      44,    0,  225,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   22,   23,
    QMetaType::Void, QMetaType::QImage,   25,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void, QMetaType::QImage,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PixamaWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PixamaWindow *_t = static_cast<PixamaWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseClickSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->colorButtonSignal((*reinterpret_cast< std::tuple<int,int,int,int>(*)>(_a[1]))); break;
        case 2: _t->toolSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->saveFileSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->openFileSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->exportAsPNGSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->exportAsJPGSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->exportFrameAsGIFSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->newFrameSignal(); break;
        case 9: _t->copyFrameSignal(); break;
        case 10: _t->selectFrameSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->playSignal(); break;
        case 12: _t->displayErrorMessageSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: _t->updateImageSlot((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 14: _t->updateFrameSelectSlot((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 15: _t->playFrameSlot((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 16: _t->on_resizeButton_clicked(); break;
        case 17: _t->on_copyButton_clicked(); break;
        case 18: _t->on_color_clicked(); break;
        case 19: _t->on_eraseButton_clicked(); break;
        case 20: _t->on_drawButton_clicked(); break;
        case 21: _t->on_bucketButton_clicked(); break;
        case 22: _t->on_actionSave_triggered(); break;
        case 23: _t->on_actionOpen_triggered(); break;
        case 24: _t->on_newFrameButton_clicked(); break;
        case 25: _t->on_frameSelectSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_actionGIF_triggered(); break;
        case 27: _t->on_actionPNG_triggered(); break;
        case 28: _t->on_actionJPG_triggered(); break;
        case 29: _t->on_playButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PixamaWindow::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::mouseClickSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)(std::tuple<int,int,int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::colorButtonSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::toolSelect)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::saveFileSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::openFileSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::exportAsPNGSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::exportAsJPGSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::exportFrameAsGIFSignal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::newFrameSignal)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::copyFrameSignal)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::selectFrameSignal)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PixamaWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PixamaWindow::playSignal)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PixamaWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PixamaWindow.data,
      qt_meta_data_PixamaWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PixamaWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PixamaWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PixamaWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PixamaWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void PixamaWindow::mouseClickSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PixamaWindow::colorButtonSignal(std::tuple<int,int,int,int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PixamaWindow::toolSelect(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PixamaWindow::saveFileSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PixamaWindow::openFileSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PixamaWindow::exportAsPNGSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PixamaWindow::exportAsJPGSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PixamaWindow::exportFrameAsGIFSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PixamaWindow::newFrameSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void PixamaWindow::copyFrameSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void PixamaWindow::selectFrameSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PixamaWindow::playSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
