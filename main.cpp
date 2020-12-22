#include <QApplication>
#include <QIcon>


#include <Game.h>

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    game = new Game();
    game->setWindowTitle("Tuk Tuk Hustle");
    game->setWindowIcon(QIcon(":/img/img/tuk.png"));
    game->show();


    return a.exec();
}
