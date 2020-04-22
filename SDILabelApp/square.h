#ifndef SQUARE_H
#define SQUARE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QtCore>
#include <QPaintEvent>
#include <QGraphicsTextItem>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QTextOption>



class Square : public QGraphicsItem
{
public:
    Square();

    QRectF boundingRect() const override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setText(const QString& text);
    QString text() const {return m_text;}

private:
    QString m_text;
};

#endif // SQUARE_H
