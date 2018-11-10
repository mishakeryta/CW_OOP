#-------------------------------------------------
#
# Project created by QtCreator 2018-11-05T22:10:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Battalion_Vertion_1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        MainWindow.cpp \
    BadBloodTypeException.cpp \
    Battalion.cpp \
    FileException.cpp \
    JsonPrasingAddition.cpp \
    LimitedDataLists.cpp \
    BadBloodTypeException.cpp \
    Military.cpp \
    ParsingException.cpp \
    MilitaryTableWidget.cpp

HEADERS += \
        MainWindow.hpp \
    BadBloodTypeException.hpp \
    BasicFunctionality.hpp \
    Battalion.hpp \
    FileException.hpp \
    JsonParsingAddition.hpp \
    LimitedDataLists.hpp \
    Military.hpp \
    ParsingException.hpp \
    Converter.hpp \
    MilitaryTableWidget.hpp

FORMS += \
        MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    BattalionData.json

RESOURCES += \
    BattalionData.qrc