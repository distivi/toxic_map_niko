#include "ExQGraphicsScene.h"
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

ExQGraphicsScene::ExQGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

QPointF ExQGraphicsScene::getPos()
{
    return this->pos;
}

void ExQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->pos = event->lastScenePos();
    qDebug() << "scene"<< this->pos;
    emit mouse_pressed();
}
