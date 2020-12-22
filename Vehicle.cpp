#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>

#include <Vehicle.h>
#include <Game.h>

Vehicle::Vehicle(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    //create vehicle
    setRect(0,0,100,100);

    //set random position
    int randomNo = rand() % 3 ? 100: 400;

    setPos(800,randomNo);

    //move the vehicle with time
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveVehicle()));

    // start the timer
    timer->start(50);


}

void Vehicle::moveVehicle()
{
    //move the vehicles towards tuk
    setPos(x()-5,y());
}
