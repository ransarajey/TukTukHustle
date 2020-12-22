#ifndef TUK_H
#define TUK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Tuk:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tuk(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawnVehicles();
};



#endif // TUK_H
