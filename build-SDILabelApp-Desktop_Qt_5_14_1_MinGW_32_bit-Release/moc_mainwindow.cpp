/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SDILabelApp/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[354];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 35), // "on_ImagesFileExplorerButton_c..."
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 19), // "updateImageFileList"
QT_MOC_LITERAL(4, 68, 8), // "filePath"
QT_MOC_LITERAL(5, 77, 35), // "on_ImagesFileList_itemDoubleC..."
QT_MOC_LITERAL(6, 113, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 130, 4), // "item"
QT_MOC_LITERAL(8, 135, 12), // "DisplayImage"
QT_MOC_LITERAL(9, 148, 11), // "std::string"
QT_MOC_LITERAL(10, 160, 8), // "fileName"
QT_MOC_LITERAL(11, 169, 16), // "getImageFilePath"
QT_MOC_LITERAL(12, 186, 36), // "on_classesFileExplorerButton_..."
QT_MOC_LITERAL(13, 223, 19), // "updateClassFileList"
QT_MOC_LITERAL(14, 243, 30), // "on_manageClassesButton_clicked"
QT_MOC_LITERAL(15, 274, 29), // "on_newClassListButton_clicked"
QT_MOC_LITERAL(16, 304, 43), // "on_imageFileListSortBox_curre..."
QT_MOC_LITERAL(17, 348, 5) // "index"

    },
    "MainWindow\0on_ImagesFileExplorerButton_clicked\0"
    "\0updateImageFileList\0filePath\0"
    "on_ImagesFileList_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0DisplayImage\0"
    "std::string\0fileName\0getImageFilePath\0"
    "on_classesFileExplorerButton_clicked\0"
    "updateClassFileList\0on_manageClassesButton_clicked\0"
    "on_newClassListButton_clicked\0"
    "on_imageFileListSortBox_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       5,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,
      13,    0,   76,    2, 0x08 /* Private */,
      14,    0,   77,    2, 0x08 /* Private */,
      15,    0,   78,    2, 0x08 /* Private */,
      16,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    0x80000000 | 9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ImagesFileExplorerButton_clicked(); break;
        case 1: _t->updateImageFileList((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_ImagesFileList_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->DisplayImage((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: { std::string _r = _t->getImageFilePath();
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->on_classesFileExplorerButton_clicked(); break;
        case 6: _t->updateClassFileList(); break;
        case 7: _t->on_manageClassesButton_clicked(); break;
        case 8: _t->on_newClassListButton_clicked(); break;
        case 9: _t->on_imageFileListSortBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE