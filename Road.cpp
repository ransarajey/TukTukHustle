#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QList>

#include <Road.h>

#include <Game.h>

#include <QDebug>

extern Game * game;

Road::Road(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    setPixmap(QPixmap(":/img/img/road-line.png"));

    setPos(800,380);


    //move the road  with time
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveRoad()));
    timer->start(40);

    // start the timer



}

void Road::moveRoad()
{



    //move the road towards tuk
    setPos(x()-15,y());

    //destroy and delete vehicle if goes out of the screen
    if (pos().x()+300 < 0){

        scene()->removeItem(this);
        delete this;


    }
}



