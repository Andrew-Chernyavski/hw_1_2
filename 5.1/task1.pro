TEMPLATE = app
QT += testlib
QT += core

CONFIG += console

SOURCES += main.cpp \
    firsthash.cpp \
    secondhash.cpp \
    hashtab.cpp

HEADERS += \
    basehash.h \
    firsthash.h \
    secondhash.h \
    hashtab.h \
    hashtest.h

