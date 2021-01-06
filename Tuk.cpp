#include <QKeyEvent>
#include <QGraphicsScene>


#include <Tuk.h>
#include <Horn.h>
#include <Vehicle.h>
#include <Game.h>
#include <Road.h>

extern Game * game;

Tuk::Tuk(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    //set tuk image
    setPixmap(QPixmap(":/img/img/tuk.png"));

    //initializing media player object
    tukhornsound = new QMediaPlayer();

}


void Tuk::keyPressEvent(QKeyEvent *event){

    //move tuk with WASD Keys
    if (event->key() == Qt::Key_W){
        if(pos().y()>245) //avoids tuk moving out of the scence
        setPos(x(),y()-180);
    }

    else if (event->key() == Qt::Key_S){
        if(pos().y()+100<425) //avoids tuk moving out of the scence
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

        if(game->horncount->getHorns()>0){
        //create a horn
        Horn * horn = new Horn();

       //set horn position
        horn->setPos(x()+80,y());
        scene()->addItem(horn);

        //play horn sound
        if( tukhornsound->state() == QMediaPlayer::StoppedState) {
              tukhornsound->setMedia(QUrl("qrc:/sfx/sfx/tukhorn.wav"));
            }
            tukhornsound->setPosition(0);
            tukhornsound->play();
        }
    }

}


void Tuk::spawnVehicles()
{
    //create a vehicle
    Vehicle * vehicle = new Vehicle();

    //add vehicle to the scene
    scene()->addItem(vehicle);


    //increase score with vehicle count
    game->score->increaseScore();
}

void Tuk::spawnRoad()
{
    //create a road line
    Road * road = new Road();

    //add road line to the scene
    scene()->addItem(road);
}







