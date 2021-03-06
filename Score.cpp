#include <QFont>

#include <Score.h>



Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    //initialize score count
    score = -1;

    //draw text
    setPlainText(QString("Score: ") + QString::number(score)); //Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Roboto",20));
}

void Score::increaseScore()
{
    //increase score
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); //Score: 0

}

int Score::getScore()
{
    return score;
}
