#include <QTimer>

#include <Horn.h>
#include <Game.h>



Horn::Horn(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    //create horn
    setRect(0,0,50,100);

    //making a timer to move the horn forward with time
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveHorn()));

    // start the timer
    timer->start(50);
}

void Horn::moveHorn()
{
    setPos(x()+10,y());

    //destroy and delete horn if goes out of the scene
    if (pos().x() - rect().width() > 800){
        scene()->removeItem(this);
        delete this;


    }
}
