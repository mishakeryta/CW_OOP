TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Military.cpp \
    BadBloodTypeException.cpp \
    LimitedDataLists.cpp

HEADERS += \
    Military.hpp \
    BadBloodTypeException.hpp \
    LimitedDataLists.hpp
