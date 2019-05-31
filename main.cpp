#include <QApplication>
#include <QWidget>

#include "database.h"
#include "window.h"

int main(int argc, char* argv[]) {

   QApplication app(argc, argv);

   Database db(NULL, "data.sqlite3");
   Window w(NULL, &db);
   w.resize(640,480);
   w.showMaximized();

   return app.exec();
}
