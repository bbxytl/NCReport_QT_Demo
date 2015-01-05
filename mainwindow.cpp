#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    report =new NCReport();
    qdb=QSqlDatabase();
    ui->radioButton_MyDS->setChecked(true);
    type=CustomData;
    setTypeOpt();
}

MainWindow::~MainWindow()
{
    if(qdb.open()){
        closeDatabase();
    }
    list.clear();
    delete report;

    delete ds;
    delete dvs;
    delete ui;
}

//按钮事件部分
void MainWindow::on_pushButton_PreView_clicked()
{
    switch (type) {
    case DataBase:
        databasePreView();
        break;
    case StrinG:
        stringPreView();
        break;
    case SList:
        listPreView();
        break;
    case CustomData:
        customPreView();
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_PDF_clicked()
{
    switch (type) {
    case DataBase:
        databasePDF();
        break;
    case StrinG:
        stringPDF();
        break;
    case SList:
        listPDF();
        break;
    case CustomData:
        customPDF();
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_HTML_clicked()
{
    qDebug()<<"没有实现功能";
}

void MainWindow::on_pushButton_Image_clicked()
{
    qDebug()<<"没有实现功能";

}

void MainWindow::on_radioButton_Acess_clicked()
{
    type=DataBase;
}

void MainWindow::on_radioButton_QString_clicked()
{
    type=StrinG;
}

void MainWindow::on_radioButton_QSList_clicked()
{
    type=SList;
}

void MainWindow::on_radioButton_MyDS_clicked()
{
    type=CustomData;
}

//设置数据部分
void MainWindow::setTypeOpt()
{
    switch (type) {
    case DataBase:
        openDatabase();
        break;
    case StrinG:
        break;
    case SList:
        list.clear();
        break;
    default:
        break;
    }
}

void MainWindow::openDatabase()
{
    if(!qdb.isOpen()){
        qdb = QSqlDatabase::addDatabase("QODBC", "db1");
        QString test = QString("DRIVER={Microsoft Access Driver (*.mdb)};\
                               FIL={MS Access};\
                               DBQ=E:/TianLong/Projects/reports/ER_DEK_22.mdb"
                              );
        qdb.setDatabaseName(test);
        qdb.open();
    }
}

void MainWindow::closeDatabase()
{
    qdb.removeDatabase("db1");
    qdb.close();
}

void MainWindow::setString()
{
    if(sdata.size()<=0){
        sdata += "1 \tChai                            \t16.0000\t1\t1540\t0\n";
        sdata += "2 \tChang                           \t17.0000\t1\t 874\t0\n";
        sdata += "3 \tAniseed Syrup                   \t 9.0000\t1\t1687\t0\n";
        sdata += "4 \tChef Anton's Cajun Seasoning    \t20.0000\t1\t1230\t0\n";
        sdata += "5 \tChef Anton's Gumbo Mixj         \t19.0000\t2\t1900\t0\n";
        sdata += "6 \tGrandma's Boysenberry Spread    \t21.0000\t2\t 520\t0\n";
        sdata += "7 \tUncle Bob's Organic Dried Pears \t25.0000\t3\t 540\t0\n";
        sdata += "8 \tNorthwoods Cranberry Sauce      \t34.0000\t3\t 120\t0\n";
        sdata += "9 \tMishi Kobe Niku                 \t72.0000\t3\t 130\t0\n";
        sdata += "10 \tIkura                          \t26.0000\t3\t2247\t0\n";
        sdata += "11 \tQueso Cabrales                 \t19.0000\t4\t 741\t0\n";
        sdata += "12 \tQueso Manchego La Pastora      \t32.0000\t4\t 512\t0\n";
        sdata += "13 \tKonbu                          \t 5.0000\t4\t1470\t0\n";
        sdata += "14 \tTofu                           \t21.0000\t4\t 978\t0\n";
        sdata += "15 \tGenen Shouyu                   \t14.0000\t4\t1005\t0\n";

        report->addParameter( "data1", sdata );
    }
}

void MainWindow::setStringList()
{
    if(list.size()<=0){
        list << "24\tRenate Moulding\tDesert Hot Springs,CA\t1\t2008-01-01";
        list << "78\tAlfred Muller\tMiami Beach, FL\t1\t2008-01-03";
        list << "140\tAngela Merkel\tMunchen, Germany\t1\t2008-01-07";
        list << "139\tBob Larson\tDallas, TX\t0\t2008-01-20";
        report->addStringList( list, "sl0" );
    }
}

void MainWindow::setCustomData()
{
#if 0
    ds= new TestDataSource();
    ds->setID("cds0");

    TestData d1;
    d1.id = 123;
    d1.name = "Alexander Henry";
    d1.address = "HOT SPRINGS VILLAGE, AR";
    d1.valid = true;
    d1.date = QDate(2008,01,10);
    ds->addData( d1 );

    TestData d2;
    d2.id = 157;
    d2.name = "Julius Coleman";
    d2.address = "Coronado, CA";
    d2.valid = false;
    d2.date = QDate(2008,01,12);
    ds->addData( d2 );

    TestData d3;
    d3.id = 157;
    d3.name = "Peter Moulding";
    d3.address = "San francisco, CA";
    d3.valid = true;
    d3.date = QDate(2008,01,07);
    ds->addData( d3 );

    report->addCustomDataSource( ds );
#endif

#if 1
    dvs = new TestVarint();
    dvs->setID("cds0");
    QStringList cols;
    cols<<"id"<<"name"<<"address"<<"valid"<<"date"<<"test";
    dvs->addCols(cols);
    QList<DATA_2> datas;
    QList<QVariant> lsv;
    lsv<<157<<"Julius"<<"Coronado, CA"
         <<false<<QDate(2008,01,12)<<"Test";
    datas.append(lsv);

    lsv.clear();
    lsv<<127<<"VILLAGE, CA"<<"Peter"
         <<"Test"<<QDate(2011,06,10)<<true;
    datas.append(lsv);

    lsv.clear();
    lsv<<157<<"Alexander"<<"San, CA"
         <<false<<QDate(2018,11,23);
    datas.append(lsv);

    dvs->addData(datas);

    report->addCustomDataSource( dvs );
#endif
    int i=0;

}

//数据显示部分
void MainWindow::databasePreView()
{
    QString templateFile="simple_cjb_demo.xml";
    report->reset();

    openDatabase();

    report->setReportSource( NCReportSource::File );
    report->setReportFile(templateFile);
    report->runReportToPreview();

    if(report->hasError()){
        qDebug()<<"Error: PreView";
        qDebug()<<report->lastErrorMsg();
    }else{
        NCReportPreviewWindow *pv = new NCReportPreviewWindow();
        pv->setOutput((NCReportPreviewOutput *)report->output());
        pv->setWindowModality(Qt::ApplicationModal);
        pv->setAttribute(Qt::WA_DeleteOnClose);
        pv->show();
    }

    closeDatabase();
}

void MainWindow::databasePDF()
{
    QString templateFile="simple_cjb_demo.xml";
    QString outFile=QString("Acess_report_%1.pdf").arg(gl_count++);

    report->reset();

    openDatabase();

    report->setReportSource( NCReportSource::File );
    report->setReportFile(templateFile);//模板文件

    report->runReportToPdf(outFile);
    closeDatabase();
}

void MainWindow::stringPreView()
{
    qDebug()<<"run the stringPreView()--Begin";
    QString templateFile="stringparameter_demo.xml";

    report->reset();

    setString();

    report->setReportSource( NCReportSource::File );
    report->setReportFile(templateFile);//模板文件
    report->runReportToPreview();
    if(report->hasError()){
        qDebug()<<"Error: stringPreView";
        qDebug()<<report->lastErrorMsg();
    }else{
        NCReportPreviewWindow *pv = new NCReportPreviewWindow();
        pv->setOutput((NCReportPreviewOutput *)report->output());
        pv->setWindowModality(Qt::ApplicationModal);
        pv->setAttribute(Qt::WA_DeleteOnClose);
        pv->show();
    }
    qDebug()<<"run the stringPreView()--End";
}

void MainWindow::stringPDF()
{
    qDebug()<<"run the stringPDF()--Begin";
    QString templateFile="stringparameter_demo.xml";
    QString outFile=QString("QString_report_%1.pdf").arg(gl_count++);

    report->reset();

    setString();

    report->setReportSource( NCReportSource::File );
    report->setReportFile(templateFile);//模板文件
    report->runReportToPdf(outFile);

    qDebug()<<"run the stringPDF()--End";

}

void MainWindow::listPreView()
{
    qDebug()<<"run the listPDF()--Begin";
    QString templateFile="stringlist_demo.xml";

    report->reset();

    setStringList();

    report->setReportSource( NCReportSource::File );
    report->setReportFile(templateFile);//模板文件
    report->runReportToPreview();
    if(report->hasError()){
        qDebug()<<"Error: ListPDFTOVIew";
        qDebug()<<report->lastErrorMsg();
    }else{
        NCReportPreviewWindow *pv = new NCReportPreviewWindow();
        pv->setOutput((NCReportPreviewOutput *)report->output());
        pv->setWindowModality(Qt::ApplicationModal);
        pv->setAttribute(Qt::WA_DeleteOnClose);
        pv->show();
    }


    qDebug()<<"run the listPDF()--End";
}

void MainWindow::listPDF()
{
    qDebug()<<"run the listPreView()--Begin";
    QString templateFile="stringlist_demo.xml";
    QString outFile=QString("List_report_%1.pdf").arg(gl_count++);

    report->reset();

    setStringList();

    report->setReportSource( NCReportSource::File );
    report->setReportFile(templateFile);//模板文件
    report->runReportToPdf(outFile);

    qDebug()<<"run the listPreView()--End";
}

void MainWindow::customPreView()
{
//    qDebug()<<"run the customPreView()--Begin";
    QString templateFile="customdatasource_demo.xml";

    report->reset();

    setCustomData();

    report->setReportSource( NCReportSource::File );
    report->setReportFile(templateFile);//模板文件
    report->runReportToPreview();
    
    if(report->hasError()){
        qDebug()<<"Error: customPreView";
        qDebug()<<report->lastErrorMsg();
    }else{
        NCReportPreviewWindow *pv = new NCReportPreviewWindow();
        pv->setOutput((NCReportPreviewOutput *)report->output());
        pv->setWindowModality(Qt::ApplicationModal);
        pv->setAttribute(Qt::WA_DeleteOnClose);
        pv->show();

    }

//    qDebug()<<"run the customPreView()--End";
}

void MainWindow::customPDF()
{
//    qDebug()<<"run the customPDF()--Begin";
    QString templateFile="customdatasource_demo.xml";
    QString outFile=QString("Custom_report_%1.pdf").arg(gl_count++);

    report->reset();

    setCustomData();
    report->setReportSource( NCReportSource::File );
    report->setReportFile(templateFile);//模板文件

//    qDebug()<<"setCustomData   1";
    report->runReportToPdf(outFile);
//    qDebug()<<"setCustomData   2";

//    qDebug()<<"run the customPDF()--End";
}
