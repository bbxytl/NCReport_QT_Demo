#include "testvarint.h"



TestVarint::TestVarint(QObject * parent) : NCReportDataSource( parent )
{
    setDataSourceType(Custom);
    setLocationType(Static);
    recno() =0;
}

TestVarint::~ TestVarint()
{
    m_lsVar.clear();
}

bool TestVarint::open()
{
    if ( m_lsVar.isEmpty() ) {
        error()->setError(QString("No data in TestVarint datasource") );
        return false;
    }
    recno() =0;
    setOpened(true);
    return true;
}

bool TestVarint::close()
{
    recno() =0;
    setOpened(false);
    return true;
}

bool TestVarint::next()
{
    recno()++;

    if ( recno() >= m_lsVar.count() ) {
        recno()--;
        flagEnd() = true;
        return false;
    }
    flagBegin() = false;
    return true;
}

int TestVarint::size() const
{
    return m_lsVar.count();
}

bool TestVarint::previous()
{
    if ( recno() <= 0 ) {
        recno() = 0;
        flagBegin() = true;
        return false;
    } else {
        recno()--;
    }
    return true;
}

bool TestVarint::first()
{
    recno()=0;
    return true;
}

bool TestVarint::last()
{
    recno() = m_lsVar.count()-1;
    return true;
}

QVariant TestVarint::value(const QString & column, bool* ok, int i ) const
{
    int col = columnIndexByName(column);
    if (col<0) {
        *ok = false;
        return QVariant();
    }
    return value( col, ok, i );
}

QVariant TestVarint::value( int column, bool*, int ) const
{
    QVariant v;
//    switch (column) {
//        case 0: v = m_lsVar.at(recno()); break;
//        case 1: v = m_lsVar.at(recno()); break;
//        case 2: v = m_lsVar.at(recno()); break;
//        case 3: v = m_lsVar.at(recno()); break;
//        case 4: v = m_lsVar.at(recno()); break;
//    }
    if(column<m_lsVar.at(recno()).size())
//    if(column<m_colName.size())
        v=m_lsVar.at(recno()).at(column);
    return v;
}

bool TestVarint::isValid() const
{
    return true;
}

bool TestVarint::read(NCReportXMLReader *)
{
    return true;
}

bool TestVarint::write(NCReportXMLWriter *)
{
    return true;
}

void TestVarint::evaluate(NCReportEvaluator *)
{
}

void TestVarint::addData(const QList<DATA_2> &datas)
{
    foreach (DATA_2 da, datas) {
        m_lsVar.append( da );
    }

}

void TestVarint::insertData(const QList<QVariant> &data, const int pos)
{
    if(pos!=-1 && pos<m_lsVar.size())
        m_lsVar.insert(pos,data);
    else
        m_lsVar.append(data);
}

void TestVarint::insertCol(const QString &columnName, const int pos)
{
    if(pos!=-1 && pos<m_colName.size())
        m_colName.insert(pos,columnName);
    else
        m_colName.append(columnName);
}

void TestVarint::addCols(const QStringList &cols)
{
    foreach (QString columnName, cols) {
        m_colName.append(columnName);
    }
}

bool TestVarint::hasNext()
{
    return (recno()<m_lsVar.count()-1);
}

bool TestVarint::seek( int index )
{
    bool ok=true;
    if ( index == -1 )
        recno() =0;
    else if ( index < m_lsVar.count())
        recno() = index;
    else
    {
        recno() = m_lsVar.count()-1;
        ok=false;
    }

    return ok;
}

int TestVarint::columnIndexByName(const QString &columnname) const
{
    for (int i=0; i<columnCount(); i++) {
        if (columnname==columnName(i))
            return i;
    }

    return -1;
}

int TestVarint::columnCount() const
{
    return m_colName.size();
}

QString TestVarint::columnName(int column) const
{
//    switch(column) {
//    case 0: return "id";
//    case 1: return "name";
//    case 2: return "address";
//    case 3: return "valid";
//    case 4: return "date";
//    }
    if(column<m_colName.size())
        return m_colName.at(column);

    return QString();
}


