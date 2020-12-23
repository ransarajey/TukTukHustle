#include <QTimer>

#include <Game.h>
#include <Vehicle.h>
#include <QImage>

#include <QDebug>


Game::Game(QWidget *parent){

    //creating a scene
    scene = new QGraphicsScene();


    //set scene size
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/img/img/bg.png")));

    //set created scene as current scene
    setScene(scene);



    //removing scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

   //create the tuk
    tuk = new Tuk();

    //set tuk size
//    tuk->setRect(0,0,100,100);

    //set tuk pos
    tuk->setPos(10,245);

    //add tuk to the scene
    scene->addItem(tuk);

    //make the tuk focusable
    tuk->setFlag(QGraphicsItem::ItemIsFocusable);
    tuk->setFocus();

    //create score
    score = new Score();
    scene->addItem(score);

    //create horns count
    horncount = new HornCount();
    horncount->setPos(x(),y()+35);
    scene->addItem(horncount);




    //spwan vehicles

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),tuk,SLOT(spawnVehicles()));
    timer->start(2000);

    //increase score
    score->increaseScore();



    show();





}



void Game::gameOver()
{
    //disable scene items
    for (int i=0, n = scene->items().size(); i<n; i++){
        scene->items()[i]->setEnabled(false);
    }



    scenetwo = new QGraphicsScene();
    scenetwo->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/img/img/bg2.png")));
    setScene(scenetwo);

    qDebug() << scene->items().size();
    qDebug() << scenetwo->items().size();



}


