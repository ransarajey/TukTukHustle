#include "HomeScreen.h"
#include "ui_HomeScreen.h"

#include <Game.h>

#include <QImage>
#include <QMessageBox>

Game * game;

HomeScreen::HomeScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeScreen)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/img/img/homeScreen.png");
        bkgnd = bkgnd.scaled(800,600, Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
}

HomeScreen::~HomeScreen()
{
    delete ui;
}

void HomeScreen::on_StartGame_clicked()
{
    this->close();
    game = new Game();
    game->setWindowTitle("Tuk Tuk Hustle");
    game->setWindowIcon(QIcon(":/img/img/tuk.png"));
    game->show();
}


void HomeScreen::on_StartGame_2_clicked()
{
    QString aboutText;
    aboutText = "01: Use WASD keys to avoid collision with the ongoing traffic. \n";
    aboutText += "02: Use horns(space) to move the traffic from your way.";

    QMessageBox::about(this,"How to play?", aboutText);

}
