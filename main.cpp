#include "mainwindow.h"
#include <QtWidgets/QApplication>


#include "AHead.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow w;
	w.show();


//    Report *report=new Report("a.pdf");
//    report->Print2Preview();
//    report->Print2PDF();

//    NCReport *report = new NCReport();
//    report->addParameter("id","value");



//    NCReport *report =new NCReport();
//    report->setReportFile("simple_cjb_demo.xml");

//    report->runReportToPreview();

	return a.exec();
}
