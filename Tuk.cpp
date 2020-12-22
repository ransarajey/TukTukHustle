#include <Tuk.h>
#include <QKeyEvent>

#include <QDebug>

Tuk::Tuk(QGraphicsItem *parent): QGraphicsRectItem(parent){

}


void Tuk::keyPressEvent(QKeyEvent *event){

    //move tuk with Arrow Keys
    if (event->key() == Qt::Key_Up){
        if(pos().y()>0)
        setPos(x(),y()-10);

        //qDebug() << pos().y()-10;

    }

    if (event->key() == Qt::Key_Down){
        if(pos().y()+100<720)
        setPos(x(),y()+10);

        qDebug() << pos().y()+100;
    }

}
