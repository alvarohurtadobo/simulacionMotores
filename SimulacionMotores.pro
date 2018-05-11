#-------------------------------------------------
#
# Project created by QtCreator 2014-05-27T17:22:34
#
#-------------------------------------------------

QT       += core gui\
            printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimulacionMotores
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graficador.cpp\
    qcustomplot.cpp \
    motorinduccion.cpp \
    fuenteca.cpp \
    generador.cpp \
    fuentedc.cpp \
    convertidor.cpp \
    variadorfrecuencia.cpp \
    dialogocurvaasincrono.cpp \
    dialogoalimentacionsincrono.cpp \
    sistemacontrol.cpp \
    pantallainicio.cpp \
    about.cpp \
    carga.cpp \
    convertidoracdccompleto.cpp

HEADERS  += mainwindow.h \
    graficador.h\
    qcustomplot.h \
    motorinduccion.h \
    fuenteca.h \
    generador.h \
    fuentedc.h \
    convertidor.h \
    variadorfrecuencia.h \
    dialogocurvaasincrono.h \
    dialogoalimentacionsincrono.h \
    sistemacontrol.h \
    pantallainicio.h \
    about.h \
    carga.h \
    convertidoracdccompleto.h

FORMS    += mainwindow.ui \
    graficador.ui
