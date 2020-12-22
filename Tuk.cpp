#include <QKeyEvent>
#include <QGraphicsScene>

#include <Tuk.h>
#include <Horn.h>
#include <Vehicle.h>




Tuk::Tuk(QGraphicsItem *parent): QGraphicsRectItem(parent){

}


void Tuk::keyPressEvent(QKeyEvent *event){

    //move tuk with Arrow Keys
    if (event->key() == Qt::Key_Up){
        if(pos().y()>0) //avoids tuk moving out of the scence
        setPos(x(),y()-10);



    }

    else if (event->key() == Qt::Key_Down){
        if(pos().y()+100<720) //avoids tuk moving out of the scence
        setPos(x(),y()+10);
    }

    else if (event->key() == Qt::Key_Left){
        if(pos().x()>0) //avoids tuk moving out of the scence
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x()+100<1080) //avoids tuk moving out of the scence
        setPos(x()+10,y());
    }


    //honk with spacebar

    else if(event->key() == Qt::Key_Space){
        //create a horn
        Horn * horn = new Horn();
        horn->setPos(x(),y());
        scene()->addItem(horn);
    }


    //spawn vehicles
}

void Tuk::spawnVehicles()
{
    //create a vehicle
    Vehicle * vehicle = new Vehicle();
    scene()->addItem(vehicle);
}
