#include "EndScreen.h"
#include "ui_EndScreen.h"
#include <QImage>

#include <Game.h>



extern Game * game;

EndScreen::EndScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EndScreen)
{
    ui->setupUi(this);

    //setting a background image for the window
    QPixmap bkgnd(":/img/img/endScreen.png");
        bkgnd = bkgnd.scaled(800,600, Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
}

EndScreen::~EndScreen()
{
    delete ui;
}


void EndScreen::on_StartGame_clicked()
{
    //when the user clicks the replay button, current window will get closed & the game window will open
    this->close();
    game = new Game();
    game->setWindowTitle("Tuk Tuk Hustle");
    game->setWindowIcon(QIcon(":/img/img/tuk.png"));
    game->show();
}
