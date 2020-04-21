#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtCore>
#include <QPaintEvent>


class Trapezium : public QGraphicsItem
{
public:
    Trapezium();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

};
#endif // TRAPEZIUM_H
