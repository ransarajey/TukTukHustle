#ifndef ROAD_H
#define ROAD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Road: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Road (QGraphicsItem * parent=0);
public slots:
    void moveRoad();
};

#endif // ROAD_H
