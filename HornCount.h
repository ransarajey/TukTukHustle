#ifndef HORNCOUNT_H
#define HORNCOUNT_H

#include <QGraphicsTextItem>

class HornCount: public QGraphicsTextItem{
public:
    HornCount(QGraphicsItem * parent=0);
    void decreaseHorns();
    int getHorns();
private:
    int horns;
};

#endif // HORNCOUNT_H
