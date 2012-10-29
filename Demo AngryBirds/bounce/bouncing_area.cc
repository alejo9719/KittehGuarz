#include <QTimer>
#include <QGraphicsScene>
#include "bounce_bird.h"
#include "bouncing_area.h"

BouncingArea::BouncingArea(QWidget* parent)
  : QGraphicsView(parent),
   // m_scene(new QGraphicsScene(0,0,5500,5500,0))
    m_scene(new QGraphicsScene(this->rect(),this))
    // m_scene(this->rect(),this)
{
  // this->setScene(&m_scene);
  this->setScene(m_scene);

  // Create the bouncing bird
  BounceBird* const bird = new BounceBird(0,m_scene);

  QTimer* const timer = new QTimer(this);
  // QObject::connect(timer, SIGNAL(timeout()), &m_scene, SLOT(advance()));
  //if (bird->getadvance()==true)
  //{
    std::cout<< "HOOLAAAAAA\n";
    QObject::connect(timer, SIGNAL(timeout()), m_scene, SLOT(advance()));
    //QObject::connect(timer, SIGNAL(clicked()), m_scene, SLOT(advance()));
  //}
  timer->setInterval(20);
  timer->start();
}


void BouncingArea::resizeEvent(QResizeEvent*)
{
  m_scene->setSceneRect(this->rect());
}
