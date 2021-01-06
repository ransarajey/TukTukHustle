#include <QTimer>
#include <QImage>

#include <Game.h>
#include <Vehicle.h>
#include <Road.h>
#include <EndScreen.h>

//creating a pointer to the endscreen
EndScreen * endScreen;

Game::Game(QWidget *parent){

    //initializing timers
    vehicleSpawnTimer = new QTimer(this);
    roadSpawnTimer = new QTimer(this);

    //creating a scene
    scene = new QGraphicsScene();


    //set scene size
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/img/img/bg.png")));

    //set created scene as current scene
    setScene(scene);

    //removing scroll bars to get a clean window
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //start the game
    startGame();

    //show the scene
    show();
}

void Game::startGame()
{
    //create the tuk
     tuk = new Tuk();

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
     QObject::connect(vehicleSpawnTimer,SIGNAL(timeout()),tuk,SLOT(spawnVehicles()));
     vehicleSpawnTimer->start(2000);

     if(!gameIsOver){

          score->increaseScore(); //increase the score until game overs
     }

     //spwan road lines
     QObject::connect(roadSpawnTimer,SIGNAL(timeout()),tuk,SLOT(spawnRoad()));
     roadSpawnTimer->start(300);
}

void Game::gameOver()
{
    //set gameIsOver variable to true
    this->gameIsOver=true;

    //close the game window and open the end screen with the score
    this->close();
    endScreen = new EndScreen();
    endScreen->setWindowTitle("Tuk Tuk Hustle");
    endScreen->setWindowIcon(QIcon(":/img/img/tuk.png"));
    endScreen->show();

    //if the score is less than 10 add a 0 to the front to keep the visual alignment
    if(score->getScore()<10)  {
        endScreen->ui->lblScore->setText(QString("0") + QString::number(score->getScore()));
    }
    else {
        endScreen->ui->lblScore->setText(QString::number(score->getScore()));
    }
}


