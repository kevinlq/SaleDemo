#-------------------------------------------------
#
# Project created by QtCreator 2017-07-28T22:23:12
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SaleClientDemo
TEMPLATE = app


QMAKE_CXXFLAGS += -std=c++0x

win32{
    CONFIG += debug_and_release
    CONFIG(release, debug|release) {
            target_path = build_/release
            TARGET  = SaleClientDemo
        } else {
            target_path = build_/debug
            TARGET  = SaleClientDemo
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
            TARGET  = SaleClientDemo
        } else {
            target_path = build_/debug
            TARGET  = SaleClientDemo
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
            TARGET  = SaleClientDemo
        } else {
            target_path = build_/debug
            TARGET  = SaleClientDemo
        }
        DESTDIR = bin
        MOC_DIR = $$target_path/moc
        RCC_DIR = $$target_path/rcc
        UI_DIR  = $$target_path/ui
        OBJECTS_DIR = $$target_path/obj
}

DEPENDPATH += bin

include ($$PWD/Src/ui/ui.pri)
include ($$PWD/Src/util/util.pri)
include ($$PWD/Src/bean/bean.pri)

INCLUDEPATH +=$$PWD/Src
INCLUDEPATH +=$$PWD/Src/util
INCLUDEPATH +=$$PWD/Src/bean

SOURCES += main.cpp

RESOURCES += \
    image.qrc
