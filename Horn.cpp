#include <QTimer>
#include <QList>
#include <stdlib.h>
#include <QGraphicsScene>

#include <Horn.h>
#include <Game.h>
#include <Vehicle.h>

extern Game * game;

Horn::Horn(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //create horn
   if(game->horncount->getHorns()>0) {
//    setRect(0,0,50,100);
       setPixmap(QPixmap(":/img/img/horn.png"));

   }

    //decrease horn
    game->horncount->decreaseHorns();

    //making a timer to move the horn forward with time
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveHorn()));

    // start the timer
    timer->start(50);
}

void Horn::moveHorn(){

    //getting a list of vehicles heard the honking
    QList<QGraphicsItem *> heardHorn = collidingItems();

    //if a vehicle heard the honking move it away
    for (int i=0, n=heardHorn.size(); i<n; i++){
        if (typeid(*(heardHorn[i])) == typeid(Vehicle)){

            int randomNo = rand() % 2 ? 110: -110;

            //move the vehicle
            if(heardHorn[i]->pos().y() < 170){
            heardHorn[i]->setPos(x(),y()+100);}
            else  {heardHorn[i]->setPos(x(),y()-245);}


        }

    }



    setPos(x()+10,y());

    //destroy and delete horn if goes out of the scene
    if (pos().x() - 100 > 800){
        scene()->removeItem(this);
        delete this;


    }
}
