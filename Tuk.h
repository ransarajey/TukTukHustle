#ifndef TUK_H
#define TUK_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Tuk:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Tuk(QGraphicsItem * parent=0);


};

#endif // TUK_H
