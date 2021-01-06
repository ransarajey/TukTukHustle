#ifndef TUK_H
#define TUK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Tuk:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tuk(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawnVehicles();
    void spawnRoad();

private:
    QMediaPlayer * tukhornsound;

};

#endif // TUK_H
