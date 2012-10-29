#ifndef BONCING_AREA_H
#define BONCING_AREA_H

#include <QGraphicsView>

struct BouncingArea
  : public QGraphicsView
{
  BouncingArea(QWidget* parent = 0);

protected:
  void resizeEvent(QResizeEvent* event);

private:
  QGraphicsScene* const m_scene;
};

#endif /* BONCING_AREA_H */
