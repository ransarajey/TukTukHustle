#include "EndScreen.h"
#include "ui_EndScreen.h"

EndScreen::EndScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EndScreen)
{
    ui->setupUi(this);
}

EndScreen::~EndScreen()
{
    delete ui;
}

