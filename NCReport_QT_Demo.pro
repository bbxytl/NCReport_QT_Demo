#-------------------------------------------------
#
# Project created by QtCreator 2014-12-04T17:25:02
#
#-------------------------------------------------

QT       += core gui printsupport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NCReport_QT_Demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    testdatasource.cpp

HEADERS  += mainwindow.h \
    AHead.h\
    testdatasource.h

FORMS    += mainwindow.ui


LIBS += D:/NCReport/API/NCReport2.13.0.MinGW.Qt5.3.2.eval/lib/NCReportDebug2.lib

INCLUDEPATH += D:/NCReport/API/NCReport2.13.0.MinGW.Qt5.3.2.eval/include
INCLUDEPATH += D:/Qt/Qt5.3.1/5.3/mingw482_32/include/QtCore/5.3.1
DEPENDPATH += D:/NCReport/API/NCReport2.13.0.MinGW.Qt5.3.2.eval/include
DEPENDPATH += D:/Qt/Qt5.3.1/5.3/mingw482_32/include/QtCore/5.3.1
