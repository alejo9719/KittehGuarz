#ifndef BOUNCE_WINDOW_HPP
#define BOUNCE_WINDOW_HPP

#include <QMainWindow>

class BounceWindow 
  : public QMainWindow
{
  Q_OBJECT
    
public:
  explicit BounceWindow(QWidget *parent = 0);
  ~BounceWindow();
};

#endif /* BOUNCE_WINDOW_HPP */
