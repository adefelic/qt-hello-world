CONFIG += c++14
TEMPLATE = app
TARGET = qt-hello-world
INCLUDEPATH += .

QT += widgets
QT += quick
QT += network

# Input
HEADERS += components/*.h
HEADERS += debug.h

SOURCES += main.cpp
SOURCES += components/*.cpp
SOURCES += debug.cpp

RESOURCES += main.qrc
