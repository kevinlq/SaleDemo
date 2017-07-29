#-------------------------------------------------
#
# Project created by QtCreator 2017-07-29T00:10:25
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SaleServerDemo
TEMPLATE = app

DEFINES +=DEBUG_OUT

QMAKE_CXXFLAGS += -std=c++0x

win32{
    CONFIG += debug_and_release
    CONFIG(release, debug|release) {
            target_path = build_/release
            TARGET  = SaleServerDemo
        } else {
            target_path = build_/debug
            TARGET  = SaleServerDemo
        }
        DESTDIR = bin
        MOC_DIR = $$target_path/moc
        RCC_DIR = $$target_path/rcc
        UI_DIR  = $$target_path/ui
        OBJECTS_DIR = $$target_path/obj
}
unix{
    CONFIG += debug_and_release
    CONFIG(release, debug|release) {
            target_path = build_/release
            TARGET  = SaleServerDemo
        } else {
            target_path = build_/debug
            TARGET  = SaleServerDemo
        }
        DESTDIR = bin
        MOC_DIR = $$target_path/moc
        RCC_DIR = $$target_path/rcc
        UI_DIR  = $$target_path/ui
        OBJECTS_DIR = $$target_path/obj
}else{
    CONFIG += debug_and_release
    CONFIG(release, debug|release) {
            target_path = build_/release
            TARGET  = SaleServerDemo
        } else {
            target_path = build_/debug
            TARGET  = SaleServerDemo
        }
        DESTDIR = bin
        MOC_DIR = $$target_path/moc
        RCC_DIR = $$target_path/rcc
        UI_DIR  = $$target_path/ui
        OBJECTS_DIR = $$target_path/obj
}

DEPENDPATH += bin

include ($$PWD/Src/ui/ui.pri)
include ($$PWD/Src/db/db.pri)
include ($$PWD/Src/util/util.pri)
include ($$PWD/Src/tcpserver/tcpserver.pri)
include ($$PWD/Src/bean/bean.pri)

INCLUDEPATH +=$$PWD/Src
INCLUDEPATH +=$$PWD/Src/db
INCLUDEPATH +=$$PWD/Src/util
INCLUDEPATH +=$$PWD/Src/tcpserver
INCLUDEPATH +=$$PWD/Src/bean

SOURCES += main.cpp
