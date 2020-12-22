#include <QTimer>

#include <Game.h>
#include <Vehicle.h>




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

   //create the tuk
    tuk = new Tuk();

    //set tuk size
    tuk->setRect(0,0,100,100);

    //set tuk pos
    tuk->setPos(10,200);

    //add tuk to the scene
    scene->addItem(tuk);

    //make the tuk focusable
    tuk->setFlag(QGraphicsItem::ItemIsFocusable);
    tuk->setFocus();

    //spwan vehicles

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),tuk,SLOT(spawnVehicles()));
    timer->start(2000);

    show();





};
