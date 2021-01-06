#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EndScreen; }
QT_END_NAMESPACE

class EndScreen : public QMainWindow
{
    Q_OBJECT

public:
    EndScreen(QWidget *parent = nullptr);
    ~EndScreen();

private:
    Ui::EndScreen *ui;
};
#endif // ENDSCREEN_H
