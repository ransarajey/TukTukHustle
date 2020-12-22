#ifndef VEHICLE_H
#define VEHICLE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Vehicle: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Vehicle(QGraphicsItem * parent=0);
public slots:
    void moveVehicle();
};

#endif // VEHICLE_H
