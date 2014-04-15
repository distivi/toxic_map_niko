#ifndef EXQGRAPHICSSCENE_H
#define EXQGRAPHICSSCENE_H

#include <QGraphicsScene>

class ExQGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ExQGraphicsScene(QObject *parent = 0);
    QPointF getPos();

private:
    QPointF pos;


signals:
    void mouse_pressed();

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // EXQGRAPHICSSCENE_H
