#ifndef WINDOW_H
#define WINDOW_H

#include "database.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

class Window : public QWidget
{
    Q_OBJECT

    QLineEdit *line;
    QPushButton *btn;
    QTextEdit *txt;

    Database *m_db;

public:
    explicit Window(QWidget *parent = 0, Database *db = 0);

signals:

public slots:
    bool find();
    bool output();

};

#endif // WINDOW_H
