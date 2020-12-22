#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>

#include <Tuk.h>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

     QGraphicsScene * scene;
     Tuk * tuk;




};

#endif // GAME_H
