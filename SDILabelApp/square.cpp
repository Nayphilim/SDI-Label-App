#include "square.h"

Square::Square()
{
 setAcceptDrops(true);
}

QRectF Square::boundingRect() const
{
    return QRectF(0,0,120,120);


}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rec(10,15,100,100);
    QPen redpen(Qt::red);
    redpen.setWidth(4);

    painter->setPen(redpen);
    painter->drawRect(rec);
    painter->drawText(boundingRect(),m_text,QTextOption(Qt::AlignHCenter));

    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setFlag(ItemIsSelectable);
}

void Square::setText(const QString &text)
{
    this->m_text = text;
    update();
}


void Square::dropEvent(QGraphicsSceneDragDropEvent *event)
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

