#include "shape.h"

Shape::Shape(std::string type)
{
 this->type = type;
 if (type == "square"){
         points.push_back({10,10});
         points.push_back({100,10});
         points.push_back({100,100});
         points.push_back({10,100});
 }
 else if (type == "trapezium"){
         points.push_back({80,10});
         points.push_back({170,10});
         points.push_back({190,60});
         points.push_back({60,60});
 }
 else if (type == "triangle"){
         points.push_back({75,25});
         points.push_back({25,125});
         points.push_back({125,125});
 }

 setAcceptDrops(true);
}

QRectF Shape::boundingRect() const
{
    if (type == "square"){
        return QRectF(0,0,120,120);
    }
    else if (type == "trapezium"){
        return QRectF(50,-5,150,70);
            }
    else if (type == "triangle"){
        return QRectF(0,0,150,150);
    }
}

void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF poly;

    for(int i = 0; i < points.size(); i++){
        poly << QPointF(points.at(i).at(0),points.at(i).at(1));
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

