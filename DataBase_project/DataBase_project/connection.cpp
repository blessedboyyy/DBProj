#include "connection.h"

bool
Connection::initConnection(QString& dbName)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( dbName );
        if( !db.open() ) {
            qDebug() << db.lastError().text();

        }
    model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.exec("SELECT * FROM customers LIMIT 10");
    model->setQuery(query);

    nameTables = db.tables();
    model->destroyed();

    return true;
}

void
Connection::selectAll(const QString& nameTable)
{
    model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.exec("select * from " + nameTable);
    model->setQuery(query);
}

void
Connection::setQuert(const QString& query)
{
    model = new QSqlQueryModel();
    QSqlQuery Query(db);
    Query.exec(query);
    model->setQuery(Query);
}
