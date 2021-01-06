#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QMainWindow>
#include <ui_EndScreen.h>

QT_BEGIN_NAMESPACE
namespace Ui { class EndScreen; }
QT_END_NAMESPACE

class EndScreen : public QMainWindow
{
    Q_OBJECT

public:
    EndScreen(QWidget *parent = nullptr);
    ~EndScreen();
     Ui::EndScreen *ui;

private slots:
    void on_StartGame_clicked();

private:
//    Ui::EndScreen *ui;
};
#endif // ENDSCREEN_H
