#include "bounce_window.h"
#include "bouncing_area.h"

BounceWindow::BounceWindow(QWidget* parent)
{
  BouncingArea* bounce = new BouncingArea(this);
  this->setCentralWidget(bounce);
}

BounceWindow::~BounceWindow()
{
}
