#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[]) {
  
  QApplication app(argc, argv);

  RemoveLineBreakWidget w;
  w.show ();
  
  return app.exec();
}
