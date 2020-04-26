#ifndef SHAPE_H
#define SHAPE_H

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



class Shape : public QGraphicsItem
{
public:
     ///initialises the Shape to be created
    Shape(std::string);
    ///used to initialise an area for shapes to be drawn and interacted with
    QRectF boundingRect() const override;
    ///overrides the dropEvent to allow for the shape to accept the class file text
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    ///overrides the paint to allow for painting the specified shape
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    ///initialises the information for which will allow for the shape to place the
    void setText(const QString& text);
    QString text() const {return m_text;}
    std::string type;
    std::vector<std::vector<int>> points;
private:
    ///initialises the text for class placing
    QString m_text;

};

#endif // SQUARE_H
