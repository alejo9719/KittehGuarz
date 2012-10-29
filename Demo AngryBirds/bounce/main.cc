#include <QtGui/QApplication>
#include "bounce_window.h"
#include "bouncing_area.h"

int main(int argc, char *argv[])
{
  QApplication app(argc,argv);
  BounceWindow win;
  win.show();
  return app.exec();
}
