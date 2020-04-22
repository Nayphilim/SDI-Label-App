#include "triangle.h"


Triangle::Triangle()
{
    setAcceptDrops(true);
}

QRectF Triangle::boundingRect() const
{
    return QRectF(0,0,150,150);
}



void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPolygonF tri;
    tri << QPointF(75,25);
    tri << QPointF(25,125);
    tri << QPointF(125,125);


    QPen linepen(Qt::red);
    linepen.setWidth(4);

    painter->setPen(linepen);
    painter->drawPolygon(tri);
    painter->drawText(boundingRect(),m_text,QTextOption(Qt::AlignHCenter));

    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsSelectable);

}

void Triangle::setText(const QString &text)
{
    this->m_text = text;
    update();
}


void Triangle::dropEvent(QGraphicsSceneDragDropEvent *event)
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




