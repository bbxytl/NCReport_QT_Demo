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

#添加库文件路径
LIBS += D:/API/NCReport/2.13.0.MinGW.Qt5.3.2.eval/lib/libNCReportDebug2.a

#添加包含路径
INCLUDEPATH += D:/API/NCReport/2.13.0.MinGW.Qt5.3.2.eval/include
INCLUDEPATH += C:/Qt/Qt5.3.1/5.3/mingw482_32/include/QtCore/5.3.1
#添加搜索路径
DEPENDPATH += D:/API/NCReport/2.13.0.MinGW.Qt5.3.2.eval/include
DEPENDPATH += C:/Qt/Qt5.3.1/5.3/mingw482_32/include/QtCore/5.3.1
