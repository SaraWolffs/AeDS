TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
	matrix.cpp \
    wormholeCalc.cpp


include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    matrix.h
