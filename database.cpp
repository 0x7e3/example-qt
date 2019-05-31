#include "database.h"

#include <QDebug>
#include <QString>

Database::Database(QObject *parent, QString dbName) :
    QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE", "data");
    db.setDatabaseName("./" + dbName);

    db = QSqlDatabase::database("data");

    if (!db.open()){
       qDebug() << "Error: connection with database failed";
    } else {
       qDebug() << "Database: connection ok";
    }
}

QSqlQuery *Database::search(QString sql){
    result = new QSqlQuery(db);

    if (!result->exec(sql)){
          qDebug() << "Error: execute failed";
    } else {
          qDebug() << "Database: execute ok";
    }

    return result;
}

QSqlQuery *Database::getResult()
{
    return result;
}
