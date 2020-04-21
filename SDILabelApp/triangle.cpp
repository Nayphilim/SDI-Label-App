#include "triangle.h"


Triangle::Triangle()
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);

}




void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPolygonF tri;
    tri << QPointF(100,50);
    tri << QPointF(50,150);
    tri << QPointF(150,150);


    QPen linepen(Qt::red);
    linepen.setWidth(4);

    painter->setPen(linepen);

    painter->drawPolygon(tri);

}

QRectF Triangle::boundingRect() const
{
    return QRectF(0,0,150,150);
}


QGraphicsTextItem *Triangle::getClassName()
{
    return className;
}

void Triangle::setClassName(QGraphicsTextItem *value)
{
    className = value;
}



