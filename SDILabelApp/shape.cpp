#include "shape.h"

Shape::Shape(int shapeNum)
{
 this->shapeNum = shapeNum;
 setAcceptDrops(true);
}

QRectF Shape::boundingRect() const
{
    switch (shapeNum){
        case 1:
            return QRectF(0,0,120,120);
        case 2:
            return QRectF(0,0,200,70);
        case 3:
            return QRectF(0,0,150,150);
    }
}

void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF poly;
    switch (shapeNum){
        case 1:
            poly << QPointF(10,10);
            poly << QPointF(100,10);
            poly << QPointF(100,100);
            poly << QPointF(10,100);
            break;
        case 2:
            poly << QPointF(10,60);
            poly << QPointF(80,10);
            poly << QPointF(170,10);
            poly << QPointF(190,60);
            break;
        case 3:
            poly << QPointF(75,25);
            poly << QPointF(25,125);
            poly << QPointF(125,125);
            break;

    }

    QPen linepen(Qt::red);
    linepen.setWidth(4);

    painter->setPen(linepen);
    painter->drawPolygon(poly);
    painter->drawText(boundingRect(),m_text,QTextOption(Qt::AlignTop));

    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsSelectable);
}

void Shape::setText(const QString &text)
{
    this->m_text = text;
    update();
}


void Shape::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
    {
        QByteArray itemData = event->mimeData()->data(
                    "application/x-qabstractitemmodeldatalist");
        QDataStream stream(&itemData, QIODevice::ReadOnly);
        int row, col;
        QMap<int, QVariant> valueMap;
        stream >> row >> col >> valueMap;
        if(!valueMap.isEmpty())
           setText(valueMap.value(0).toString());
        event->accept();
    }
    else
        event->ignore();
}

