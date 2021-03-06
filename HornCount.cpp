#include <QFont>

#include <HornCount.h>



HornCount::HornCount(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    //initialize horn count
    horns = 5;

    //draw text
    setPlainText(QString("Horns: ") + QString::number(horns)); //Horns: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("Roboto",20));
}

void HornCount::decreaseHorns()
{
    //decrease horns
    horns--;
    if(getHorns()>-1){
    setPlainText(QString("Horns: ") + QString::number(horns));} //Horns: 1

}

int HornCount::getHorns()
{
    return horns;
}
