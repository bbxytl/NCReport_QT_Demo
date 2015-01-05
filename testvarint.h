#ifndef TESTVARINT_H
#define TESTVARINT_H

#include "AHead.h"
#include <QDate>



typedef QList<QVariant> DATA_2;

class TestVarint : public NCReportDataSource
{
    Q_OBJECT
public:
    TestVarint( QObject *parent=0 );
    ~TestVarint();

    void addData(const QList<DATA_2> &datas );   //add the datas to DataSource
    void addCols(const QStringList &cols);     //add the cols to DataSource

    void insertData(const QList<QVariant> &data,const int pos=-1);   //add one data
    void insertCol(const QString &columnName,const int pos=-1);      //add one col

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
    QList<DATA_2> m_lsVar;        //save the all data(all Type)
    QStringList m_colName;      //save the colName of the data
};

#endif // TESTVARINT_H
