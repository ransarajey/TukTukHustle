#include <QApplication>


#include <Game.h>

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    game = new Game();
    game->setWindowTitle("Tuk Tuk Hustle");
    game->show();


    return a.exec();
}
