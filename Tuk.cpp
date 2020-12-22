#include <QKeyEvent>
#include <QGraphicsScene>


#include <Tuk.h>
#include <Horn.h>
#include <Vehicle.h>
#include <Game.h>


#include <QDebug>

extern Game * game;

Tuk::Tuk(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/img/img/tuk.png"));


}


void Tuk::keyPressEvent(QKeyEvent *event){

    //move tuk with Arrow Keys
    if (event->key() == Qt::Key_W){
        if(pos().y()>0) //avoids tuk moving out of the scence
        setPos(x(),y()-180);



    }

    else if (event->key() == Qt::Key_S){
        if(pos().y()+100<600) //avoids tuk moving out of the scence
        setPos(x(),y()+180);
    }

    else if (event->key() == Qt::Key_A){
        if(pos().x()>0) //avoids tuk moving out of the scence
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_D){
        if(pos().x()+100<800) //avoids tuk moving out of the scence
        setPos(x()+10,y());
    }


    //honk with spacebar

    else if(event->key() == Qt::Key_Space){
        //create a horn
        Horn * horn = new Horn();
        horn->setPos(x()+80,y());
        scene()->addItem(horn);
    }



}


void Tuk::spawnVehicles()
{
    //create a vehicle
    Vehicle * vehicle = new Vehicle();
    scene()->addItem(vehicle);

    qDebug() << "Added vehicle";
    //increase score
    game->score->increaseScore();


}





