#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql/QtSql>

class Database : public QObject
{
    Q_OBJECT
    QSqlDatabase db;
    QSqlQuery *result;

public:
    explicit Database(QObject *parent = 0, QString dbName = "");

signals:

public slots:
    QSqlQuery *search(QString sql = "");
    QSqlQuery *getResult();

};

#endif // DATABASE_H
