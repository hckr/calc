TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    commandinput.cpp

LIBS += -lncurses

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    commandinput.h

