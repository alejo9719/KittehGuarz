#ifndef BOUNCE_BIRD_H
#define BOUNCE_BIRD_H

#include <iostream>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>

struct BounceBird
	: public QGraphicsItem
{
  BounceBird(QGraphicsItem* parent, QGraphicsScene* scene);

  // Move the object
  void advance(int phase);

  QRectF boundingRect() const;

  // Collision shape
  QPainterPath shape() const;

  void paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget* widget);
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

  bool getadvance();

private:
  bool avanzar;
  double m_dx;
  double m_dy;
  double Vx, Vy;
  double angulo;
  double velocidad;
  double timet;
  float g;

  // Parent scene
  QGraphicsScene* const m_scene;

  QGraphicsPixmapItem*  m_pic;
  QGraphicsPixmapItem*  m_pic2;

};

#endif /* BOUNCE_BIRD_H */