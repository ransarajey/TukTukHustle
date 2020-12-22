#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QList>

#include <Vehicle.h>
#include <Horn.h>
#include <Game.h>

extern Game * game;

Vehicle::Vehicle(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    //create vehicle
    setRect(0,0,100,100);

    //set random position
    int randomNo = rand() % 2 ? 200: 300;

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

    //destroy and delete vehicle if goes out of the screen
    if (pos().x()+rect().width() < 0){

        scene()->removeItem(this);
        delete this;



    }
}



