#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include <iostream>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Con_db = new Connection();
    initConnection();


//    db = QSqlDatabase::addDatabase( "QSQLITE" );
//    db.setDatabaseName( "C:/Users/alexf/Downloads/chinook/chinook.db" );
//        if( !db.open() ) {
//            qDebug() << db.lastError().text();

//        }
//    model = new QSqlQueryModel(this);
//    QSqlQuery query(db);
//    query.exec("SELECT * FROM customers LIMIT 10");
//    model->setQuery(query);

//    QStringList list = db.tables();
//    for (auto l : list){
//        std::cout << l.toStdString() << std::endl;
//    }
//    QSqlDatabase::tables(), QSqlDatabase::recordInfo()

    // Установите модель в QTableView
//    QTableView *tableView = new QTableView(this);
//    tableView->setModel(model);
//    tableView->show();

//    query =  new QSqlQuery(db);
//    query->exec("SELECT * FROM chinook.customers limit 10 ");

//    model = new QSqlTableModel(this, db);
//    model->setTable("customers");
//    model->setQuery(query);

    ui->tableView->setModel(Con_db->getModel());


}

void
MainWindow::initConnection()
{
    QString pathToDB = "C:/Users/alexf/Downloads/chinook/chinook.db";
    QStringList nameTables;
    Con_db->initConnection(pathToDB);
    ui->tableView->setModel(Con_db->getModel());

    for (auto item : Con_db->getNamesTables()){
         ui->comboBox->addItem(item);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    std::cout << arg1.toStdString() << std::endl;
    Con_db->selectAll(arg1);
    ui->tableView->setModel(Con_db->getModel());
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    Con_db->setQuert(text);
    ui->tableView->setModel(Con_db->getModel());
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString s = QString::number(index.row()) + " " + QString::number(index.column()) + "  " + index.data().toString();
    ui->textEdit->setText(s);
}
