#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AHead.h"

#include "testdatasource.h"
#include "testvarint.h"

enum REPORTTYPE{DataBase,StrinG,SList,CustomData};
static unsigned int gl_count=0;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_PreView_clicked();
    void on_pushButton_PDF_clicked();
    void on_pushButton_HTML_clicked();
    void on_pushButton_Image_clicked();

    void on_radioButton_Acess_clicked();
    void on_radioButton_QString_clicked();
    void on_radioButton_QSList_clicked();
    void on_radioButton_MyDS_clicked();

private:
    void setTypeOpt();
    //Access
    void openDatabase();
    void closeDatabase();
    //QString
    void setString();
    //QStringList
    void setStringList();
    //Custom Data
    void setCustomData();
private:
    //数据库
    void databasePreView();
    void databasePDF();
    //QString
    void stringPreView();
    void stringPDF();
    //QStringList
    void listPreView();
    void listPDF();
    //Custom Data
    void customPreView();
    void customPDF();

private:
    Ui::MainWindow *ui;    
    NCReport * report;
    REPORTTYPE type;    //类型
    QSqlDatabase qdb;   //数据库链接数据
    QString sdata;      //数据源为QString
    QStringList list;   //数据源为QStringList
    TestDataSource *ds ;//数据源为CustomData
    TestVarint *dvs;

};

#endif // MAINWINDOW_H
