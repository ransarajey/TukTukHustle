#ifndef HORN_H
#define HORN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

#include <QObject>

class Horn: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Horn(QGraphicsItem * parent=0);
public slots:
    void moveHorn();
};

#endif // HORN_H
