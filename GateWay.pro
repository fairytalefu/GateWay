#-------------------------------------------------
#
# Project created by QtCreator 2017-05-11T10:21:48
#
#-------------------------------------------------

QT       += core gui
QT       += sql serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GateWay
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_*.so

SOURCES += main.cpp\
        gateway.cpp \
    model.cpp \
    serial.cpp \
    video.cpp \
    map.cpp

HEADERS  += gateway.h \
    model.h \
    serial.h \
    video.h \
    map.h

FORMS    += gateway.ui
