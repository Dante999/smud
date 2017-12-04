TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pugixml.cpp \
    itemstorage.cpp \
    item.cpp \
    dataService.cpp \
    directions.cpp \
    gameEngine.cpp \
    gameObject.cpp \
    livingOrganism.cpp \
    logger.cpp \
    player.cpp \
    room.cpp \
    roomEngine.cpp \
    session.cpp \
    stringHelper.cpp \
    interpreter.cpp

HEADERS += \
    pugiconfig.hpp \
    pugixml.hpp \
    itemstorage.h \
    item.h \
    dataService.h \
    directions.h \
    gameEngine.h \
    gameObject.h \
    gender.h \
    livingOrganism.h \
    logger.h \
    player.h \
    room.h \
    roomEngine.h \
    session.h \
    stringHelper.h \
    interpreter.h

