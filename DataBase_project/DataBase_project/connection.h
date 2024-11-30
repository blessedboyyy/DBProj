#ifndef CONNECTION_H
#define CONNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include "QSqlTableModel"
#include <QtSql>
#include <QSqlDatabase>

class Connection{
public:
    Connection() {};
    QSqlQueryModel* getModel() const { return model;}
    QStringList getNamesTables() const { return nameTables;}

    void selectAll(const QString& nameTable);
    void setQuert(const QString& query);

    bool initConnection(QString& dbName);

private:
    QStringList nameTables;
    QSqlDatabase db;
    QSqlQueryModel *model;

};



#endif // CONNECTION_H
