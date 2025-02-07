QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cargar_guardar.cpp \
    cargararchivos.cpp \
    creardocumentos.cpp \
    dni.cpp \
    main.cpp \
    mainwindow.cpp \
    niveles.cpp \
    reglas.cpp \
    ticket_de_entrada.cpp \
    trabajo.cpp \
    visa.cpp

HEADERS += \
    cargar_guardar.h \
    cargararchivos.h \
    creardocumentos.h \
    dni.h \
    mainwindow.h \
    niveles.h \
    reglas.h \
    ticket_de_entrada.h \
    trabajo.h \
    visa.h

FORMS += \
    dni.ui \
    mainwindow.ui \
    reglas.ui \
    ticket_de_entrada.ui \
    trabajo.ui \
    visa.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
