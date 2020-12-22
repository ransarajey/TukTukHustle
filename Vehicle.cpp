#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QList>

#include <Vehicle.h>
#include <Horn.h>
#include <Game.h>

#include <QDebug>

extern Game * game;

Vehicle::Vehicle(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //create vehicle
//    setRect(0,0,100,100);

    int whichCar = rand() % 2 ? 1: 2;

    if(whichCar==1)
    setPixmap(QPixmap(":/img/img/car-blue.png"));
    else setPixmap(QPixmap(":/img/img/car-yellow.png"));


    //set random position
    int randomNo = rand() % 2 ? 160: 360;

    setPos(800,randomNo);

    //move the vehicle with time
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveVehicle()));

    // start the timer
    timer->start(40);


}

void Vehicle::moveVehicle()
{



    //getting a list of vehicles collided with the tuk
    QList<QGraphicsItem *> collidedCars = collidingItems();

    //if a vehicle crashed with the tuk gameOver
    for (int i=0, n=collidedCars.size(); i<n; i++){
        if (typeid(*(collidedCars[i])) == typeid(Tuk)){
            game->gameOver();
        }
        }

    //if a vehicle crashed with a vehicle destroy
    for (int i=0, n=collidedCars.size(); i<n; i++){
        if (typeid(*(collidedCars[i])) == typeid(Vehicle)){
            scene()->removeItem(collidedCars[i]);
            delete collidedCars[i];

        }
        }


    //move the vehicles towards tuk
    setPos(x()-5,y());

    //destroy and delete vehicle if goes out of the screen
    if (pos().x()+100 < 0){

        scene()->removeItem(this);
        delete this;



    }
}



