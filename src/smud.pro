TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CommandParser.cpp \
    DataService.cpp \
    Directions.cpp \
    GameObject.cpp \
    InteractionEngine.cpp \
    LivingOrganism.cpp \
    Logger.cpp \
    Player.cpp \
    pugixml.cpp \
    Room.cpp \
    RoomEngine.cpp \
    Session.cpp \
    StringHelper.cpp

HEADERS += \
    CommandParser.h \
    DataService.h \
    Directions.h \
    GameObject.h \
    Gender.h \
    InteractionEngine.h \
    LivingOrganism.h \
    Logger.h \
    Player.h \
    Room.h \
    RoomEngine.h \
    Session.h \
    StringHelper.h \
    pugiconfig.hpp \
    pugixml.hpp

