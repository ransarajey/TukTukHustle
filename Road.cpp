#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QList>

#include <Road.h>
#include <Game.h>

// initializing an external variable pointer
extern Game * game;

Road::Road(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //set an image to rode lines
    setPixmap(QPixmap(":/img/img/road-line.png"));

    //set position for road lines
    setPos(800,380);

    //move the road  with time using a timer
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveRoad()));

    // start the timer
    timer->start(40);

}

void Road::moveRoad()
{
    //move the road towards tuk
    setPos(x()-15,y());

    //destroy and delete road lines if goes out of the screen
    if (pos().x()+50 < 0){
        scene()->removeItem(this);
        delete this;
    }
}



