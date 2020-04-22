#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtCore>
#include <QPaintEvent>
#include <QGraphicsTextItem>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QTextOption>
#include <QFont>

class Triangle : public QGraphicsItem
{
public:
    Triangle();

    QRectF boundingRect() const override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setText(const QString& text);
    QString text() const {return m_text;}

private:
    QString m_text;


};



#endif // TRIANGLE_H
