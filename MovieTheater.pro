QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addwindow.cpp \
    bosswindow.cpp \
    costumerwindow.cpp \
    editsearchwindow.cpp \
    editwindow.cpp \
    homewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    removesearchwindow.cpp \
    removewindow.cpp \
    searchwindow.cpp \
    showdatawindow.cpp \
    signupwindow.cpp \
    reservewindow.cpp \
    historywindow.cpp

HEADERS += \
    addwindow.h \
    bosswindow.h \
    costumerwindow.h \
    editsearchwindow.h \
    editwindow.h \
    homewindow.h \
    mainwindow.h \
    removesearchwindow.h \
    removewindow.h \
    searchwindow.h \
    showdatawindow.h \
    signupwindow.h \
    reservewindow.h \
    historywindow.h

FORMS += \
    addwindow.ui \
    bosswindow.ui \
    costumerwindow.ui \
    editsearchwindow.ui \
    editwindow.ui \
    homewindow.ui \
    mainwindow.ui \
    removesearchwindow.ui \
    removewindow.ui \
    searchwindow.ui \
    showdatawindow.ui \
    signupwindow.ui \
    reservewindow.ui \
    historywindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc
