#include "trapezium.h"

Trapezium::Trapezium()
{
    setAcceptDrops(true);
}

QRectF Trapezium::boundingRect() const
{
    return QRectF(0,0,200,70);
}


void Trapezium::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF trap;
    trap << QPointF(10,60);
    trap << QPointF(80,10);
    trap << QPointF(170,10);
    trap << QPointF(190,60);


    QPen linepen(Qt::red);
    linepen.setWidth(4);

    painter->setPen(linepen);
    painter->drawPolygon(trap);
    painter->drawText(boundingRect(),m_text,QTextOption(Qt::AlignTop));

    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsSelectable);
}

void Trapezium::setText(const QString &text)
{
    this->m_text = text;
    update();
}


void Trapezium::dropEvent(QGraphicsSceneDragDropEvent *event)
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
