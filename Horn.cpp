#include <QTimer>

#include <Horn.h>
#include <Game.h>


Horn::Horn(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    //create horn
    setRect(0,0,50,100);

    //making a timer to move the horn forward with time
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Horn::move()
{
    setPos(x()+10,y());
}
