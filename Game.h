#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <Tuk.h>
#include <Score.h>
#include <HornCount.h>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

     QGraphicsScene * scene;
     Tuk * tuk;
     Score * score;
     HornCount * horncount;




};

#endif // GAME_H
