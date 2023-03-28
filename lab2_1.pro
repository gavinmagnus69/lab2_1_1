QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calls.cpp \
    fromfile.cpp \
    listcalls.cpp \
    listuser.cpp \
    main.cpp \
    mainwindow.cpp \
    user.cpp

HEADERS += \
    calls.h \
    fromfile.h \
    listcalls.h \
    listuser.h \
    mainwindow.h \
    user.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-lab2_1-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/database.txt
