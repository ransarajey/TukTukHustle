#include <Game.h>

Game::Game(QWidget *parent){

    //creating a scene
    scene = new QGraphicsScene();

    //set scene size
    scene->setSceneRect(0,0,1080,720);

    //set created scene as current scene
    setScene(scene);

    //removing scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1080,720);

};
