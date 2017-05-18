#-------------------------------------------------
#
# Project created by QtCreator 2016-12-14T07:22:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = PointGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    navgationbar.cpp \
    mainpage.cpp \
    settingcontent.cpp \
    serialconnection.cpp \
    usbconnection.cpp \
    tcpconnection.cpp \
    qcustomplot.cpp \
    cureimagecontent.cpp \
    cureimagethread.cpp

HEADERS  += mainwindow.h \
    navgationbar.h \
    mainpage.h \
    settingcontent.h \
    serialconnection.h \
    usbconnection.h \
    tcpconnection.h \
    qcustomplot.h \
    cureimagecontent.h \
    cureimagethread.h

FORMS    += mainwindow.ui \
    settingcontent.ui \
    navgationbar.ui \
    navgationbar.ui \
    mainpage.ui \
    serialconnection.ui \
    usbconnection.ui \
    tcpconnection.ui \
    cureimagecontent.ui

RESOURCES += \
    mysource.qrc
