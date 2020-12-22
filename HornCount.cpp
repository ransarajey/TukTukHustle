#include <QFont>

#include <HornCount.h>



HornCount::HornCount(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    //initialize horns
    horns = 5;

    //draw text
    setPlainText(QString("Horns: ") + QString::number(horns)); //Horns: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void HornCount::decreaseHorns()
{
    horns--;
    if(getHorns()>-1){
    setPlainText(QString("Horns: ") + QString::number(horns));} //Horns: 1

}

int HornCount::getHorns()
{
    return horns;
}
