#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtCore>
#include <QPaintEvent>
#include <QGraphicsTextItem>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QTextOption>


class Trapezium : public QGraphicsItem
{
public:
    Trapezium();

    QRectF boundingRect() const override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setText(const QString& text);
    QString text() const {return m_text;}

private:
    QString m_text;

};
#endif // TRAPEZIUM_H
