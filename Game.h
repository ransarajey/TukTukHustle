#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <Tuk.h>
#include <Score.h>
#include <HornCount.h>

#include <QTimer>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    void startGame();
    void gameOver();
    bool gameIsOver=false;
    QTimer *timer;
    QTimer *timer2;



     QGraphicsScene * scene;
     QGraphicsScene * scenetwo;
     Tuk * tuk;
     Score * score;
     HornCount * horncount;


};

#endif // GAME_H
