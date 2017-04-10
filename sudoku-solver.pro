TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += src/header/

SOURCES += \
    src/source/main.cpp \
    src/source/backtracktree.cpp

HEADERS += \
    src/header/backtracktree.h
