#include <QApplication>
#include <QIcon>


#include <Game.h>
#include <HomeScreen.h>
#include <HomeScreen.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //show home screen as the starting screen
    HomeScreen HomeScreen;
    HomeScreen.setWindowTitle("TukTuk Hustle");
    HomeScreen.setWindowIcon(QIcon(":/img/img/tuk.png"));

    HomeScreen.show();

    return a.exec();
}
