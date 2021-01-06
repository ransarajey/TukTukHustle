QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game.cpp \
    Horn.cpp \
    HornCount.cpp \
    Road.cpp \
    Score.cpp \
    Tuk.cpp \
    Vehicle.cpp \
    main.cpp \
    HomeScreen.cpp \
    EndScreen.cpp

HEADERS += \
    Game.h \
    Horn.h \
    HornCount.h \
    Road.h \
    Score.h \
    Tuk.h \
    Vehicle.h \
    HomeScreen.h \
    EndScreen.h

FORMS += \
    HomeScreen.ui \
    EndScreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc
