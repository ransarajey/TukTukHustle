#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QList>

#include <Vehicle.h>
#include <Horn.h>
#include <Game.h>


extern Game * game;

Vehicle::Vehicle(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //randmoly choosing an image for a car
    int whichCar = rand() % 2 ? 1: 2;

    if(whichCar==1)
    setPixmap(QPixmap(":/img/img/car-blue.png"));
    else setPixmap(QPixmap(":/img/img/car-yellow.png"));

    //set random position for cars
    int randomLane = rand() % 2 ? 360: 160;

    //set vehicle position
    setPos(800,randomLane);

    //move the vehicle with time using a timer
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
    for (int i=0, n=collidedCars.size(); i<n ; i++){
        if (typeid(*(collidedCars[i])) == typeid(Tuk)  && game->gameIsOver!=true){

            //stopping timers
            game->vehicleSpawnTimer->stop();
            game->roadSpawnTimer->stop();

            //calling the game over function
            game->gameOver();
        }
        }

    //if a vehicle crashed with a vehicle destroy them
    for (int i=0, n=collidedCars.size(); i<n; i++){
        if (typeid(*(collidedCars[i])) == typeid(Vehicle)){
            scene()->removeItem(collidedCars[i]);
            delete collidedCars[i];
        }
        }


    //move the vehicles towards tuk
    setPos(x()-20,y());

    //destroy and delete vehicle if goes out of the screen
    if (pos().x()+300 < 0){
        scene()->removeItem(this);
        delete this;
    }
}



