#ifndef HORN_H
#define HORN_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class Horn: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Horn(QGraphicsItem * parent=0);
public slots:
    void moveHorn();
};

#endif // HORN_H
