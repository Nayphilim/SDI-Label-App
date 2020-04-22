#ifndef RECTANGLE_H
#define RECTANGLE_H


#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtCore>
#include <QPaintEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>

class Rectangle
{
public:
    Rectangle();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // RECTANGLE_H
