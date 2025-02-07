/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "presentarVentanas",
    "",
    "nivel",
    "manejarDecision",
    "aprobado",
    "inicializarNivel",
    "actualizarContador",
    "fila",
    "int&",
    "contador",
    "Contador",
    "Iniciar_Contador",
    "cargar_planilla_de_control",
    "on_Info_button_clicked",
    "on_Jugar_Button_clicked",
    "on_Aprobado_Button_clicked",
    "on_Denegado_Button_clicked",
    "on_Guardar_Button_clicked",
    "on_Cargar_Button_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

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
       1,    1,   92,    2, 0x08,    1 /* Private */,
       4,    1,   95,    2, 0x08,    3 /* Private */,
       6,    1,   98,    2, 0x08,    5 /* Private */,
       7,    2,  101,    2, 0x08,    7 /* Private */,
      11,    0,  106,    2, 0x08,   10 /* Private */,
      12,    0,  107,    2, 0x08,   11 /* Private */,
      13,    0,  108,    2, 0x08,   12 /* Private */,
      14,    0,  109,    2, 0x08,   13 /* Private */,
      15,    0,  110,    2, 0x08,   14 /* Private */,
      16,    0,  111,    2, 0x08,   15 /* Private */,
      17,    0,  112,    2, 0x08,   16 /* Private */,
      18,    0,  113,    2, 0x08,   17 /* Private */,
      19,    0,  114,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
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

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'presentarVentanas'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'manejarDecision'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'inicializarNivel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'actualizarContador'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int &, std::false_type>,
        // method 'Contador'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Iniciar_Contador'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cargar_planilla_de_control'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Info_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Jugar_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Aprobado_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Denegado_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Guardar_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Cargar_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->presentarVentanas((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->manejarDecision((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->inicializarNivel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->actualizarContador((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int&>>(_a[2]))); break;
        case 4: _t->Contador(); break;
        case 5: _t->Iniciar_Contador(); break;
        case 6: _t->cargar_planilla_de_control(); break;
        case 7: _t->on_Info_button_clicked(); break;
        case 8: _t->on_Jugar_Button_clicked(); break;
        case 9: _t->on_Aprobado_Button_clicked(); break;
        case 10: _t->on_Denegado_Button_clicked(); break;
        case 11: _t->on_Guardar_Button_clicked(); break;
        case 12: _t->on_Cargar_Button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
