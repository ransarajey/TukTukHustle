#include <QKeyEvent>
#include <QGraphicsScene>

#include <Tuk.h>
#include <Horn.h>




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


    //honk with spacebar

    else if(event->key() == Qt::Key_Space){
        //create a horn
        Horn * horn = new Horn();
        horn->setPos(x(),y());
        scene()->addItem(horn);
    }
}
