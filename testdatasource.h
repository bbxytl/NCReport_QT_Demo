#ifndef TESTDATASOURCE_H
#define TESTDATASOURCE_H
#include "AHead.h"
#include <QDate>

struct TestData {
    int id;
    QString name;
    QString address;
    bool valid;
    QDate date;
};


class TestDataSource : public NCReportDataSource
{
    Q_OBJECT
public:
    TestDataSource( QObject *parent=0 );
    ~TestDataSource();

    void addData( const TestData& data );

    bool open();
    bool close();
    bool first();
    bool last();
    bool next();
    bool previous();
    bool hasNext();
    int size() const;
    QVariant value( const QString&, bool*, int ) const;
    QVariant value( int, bool*, int ) const;
    bool read( NCReportXMLReader* );
    bool write( NCReportXMLWriter* );
    void evaluate( NCReportEvaluator* );
    bool seek( int index );
    bool isValid() const;
    int columnIndexByName(const QString& columnname) const;
    int columnCount() const;
    QString columnName(int column) const;


private:
    QList<TestData> list;
};

#endif
