#include "window.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QPalette>
#include <QColor>

Window::Window(QWidget *parent, Database *db) :
    QWidget(parent)
{
    m_db = db;

    QVBoxLayout *verticalBox = new QVBoxLayout(this);
    QHBoxLayout *textBox = new QHBoxLayout();
    QHBoxLayout *inputBox = new QHBoxLayout();

    line = new QLineEdit(this);
    btn = new QPushButton("Ok", this);
    txt = new QTextEdit(this);

    txt->setFrameStyle(QFrame::NoFrame);
    txt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    txt->setReadOnly(true);

    QPalette grayPalette = txt->palette();
    QColor mainWindow = palette().color(QPalette::Window);
    grayPalette.setColor(QPalette::Base, mainWindow);
    txt->setPalette(grayPalette);


    setWindowTitle(tr("Database"));

    inputBox->addWidget(line);
    inputBox->addWidget(btn);
    textBox->addWidget(txt);

    verticalBox->addItem(textBox);
    verticalBox->addItem(inputBox);

    connect(btn, SIGNAL(clicked()),
                    this, SLOT(find())
                );
    connect(line, SIGNAL(returnPressed()),
                this, SLOT(find())
            );
}

bool Window::find()
{
    QString query, sqlQuery;
    query = line->text();
    query = query.trimmed();

    if (query.size() < 3)
        return false;

    sqlQuery = "SELECT title, post FROM article WHERE title LIKE '%" + query + "%'";
    m_db->search(sqlQuery);
    this->output();
}

bool Window::output()
{
   QString mainTxt, title, post;
   mainTxt = "";
   txt->setText("");

   QSqlQuery *res = 0;
   if (m_db->getResult())
       res = m_db->getResult();

   while(res->next()){
        title = res->value(0).toString();
        post = res->value(1).toString();
        mainTxt = mainTxt + title + "\n\n" + post + "\n\n * * * \n\n";
   }

   txt->setText(mainTxt);

}
