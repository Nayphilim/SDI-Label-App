#include "trapezium.h"

Trapezium::Trapezium()
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
}

QRectF Trapezium::boundingRect() const
{
    return QRectF(0,0,190,60);
}


void Trapezium::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    QPolygonF trap;
//    trap << QPointF(10,10);
//    trap << QPointF(10,100);
//    trap << QPointF(100,100);
//    trap << QPointF(100,10);

    QPolygonF trap;
    trap << QPointF(10,60);
    trap << QPointF(80,10);
    trap << QPointF(170,10);
    trap << QPointF(190,60);


    QPen linepen(Qt::red);
    linepen.setWidth(4);

    painter->setPen(linepen);

    painter->drawPolygon(trap);

}
