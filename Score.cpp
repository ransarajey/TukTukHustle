#include <QFont>

#include <Score.h>



Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    //initialize score
    score = 0;

    //draw text
    setPlainText(QString("Score: ") + QString::number(score)); //Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increaseScore()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); //Score: 0

}

int Score::getScore()
{
    return score;
}
