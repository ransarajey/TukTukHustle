#include <QTimer>

#include <Game.h>
#include <Vehicle.h>
#include <Road.h>
#include <EndScreen.h>

#include <QImage>


#include <QDebug>

EndScreen * endScreen;

Game::Game(QWidget *parent){

    timer = new QTimer(this);
    timer2 = new QTimer(this);

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



    startGame();
    show();



}

void Game::startGame()
{
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


     QObject::connect(timer,SIGNAL(timeout()),tuk,SLOT(spawnVehicles()));
     timer->start(2000);

     if(!gameIsOver){

          score->increaseScore();
     }

     //spwan road


     QObject::connect(timer2,SIGNAL(timeout()),tuk,SLOT(spawnRoad()));
     timer2->start(300);





}



void Game::gameOver()
{

    this->gameIsOver=true;


    this->close();
    endScreen = new EndScreen();
    endScreen->setWindowTitle("Tuk Tuk Hustle");
    endScreen->setWindowIcon(QIcon(":/img/img/tuk.png"));
    endScreen->show();

    if(score->getScore()<10)  {
        endScreen->ui->lblScore->setText(QString("0") + QString::number(score->getScore()));
    }
    else {
        endScreen->ui->lblScore->setText(QString::number(score->getScore()));
    }






}


