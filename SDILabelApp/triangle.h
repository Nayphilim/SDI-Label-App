#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtCore>
#include <QPaintEvent>
#include <QGraphicsTextItem>


class Triangle : public QGraphicsItem
{
public:
    Triangle();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    QGraphicsTextItem *getClassName();
    void setClassName(QGraphicsTextItem *value);

private:
    QGraphicsTextItem *className;


};



#endif // TRIANGLE_H
