QT += core

TEMPLATE = app
CONFIG += console
CONFIG += qtestlib

SOURCES += main.cpp \
    printtoconsole.cpp \
    printtofile.cpp

HEADERS += \
    printer.h \
    printtoconsole.h \
    printtofile.h \
    printertest.h

