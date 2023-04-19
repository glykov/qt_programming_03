#include <QPainter>
#include "figure.h"


Figure::Figure(int x, int y, QObject *parent)
    : QObject(parent)
    , QGraphicsItem()
    , xPos(x), yPos(y)
{
    if (figureCounter % 3 == 0) {
        geometry = Geometry::RECTANGLE;
        ++figureCounter;
    } else if (figureCounter % 3 == 1) {
        geometry = Geometry::ELLIPS;
        ++figureCounter;
    } else {
        geometry = Geometry::STAR;
        ++figureCounter;
    }

    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

int Figure::figureCounter = 0;

QRectF Figure::boundingRect() const
{
    return QRectF(xPos, yPos, 100, 50);
}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::PenStyle::SolidLine);
    QBrush brush(QColor(rand() % 256, rand() % 256, rand() % 256),
                 Qt::BrushStyle::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(brush);
    if (geometry == Geometry::RECTANGLE) {
        painter->drawRect(xPos, yPos, 100, 50);
    } else if (geometry == Geometry::ELLIPS) {
        painter->drawEllipse(xPos, yPos, 100, 50);
    } else {
        QPolygon star;
        star << QPoint(xPos + 35, yPos) << QPoint(xPos, yPos + 70)
             << QPoint(xPos + 70, yPos + 70);
//        star << QPoint(xPos - 35, yPos) << QPoint(xPos - 25, yPos + 25)
//             << QPoint(xPos, yPos + 25) << QPoint(xPos - 20, yPos + 55)
//             << QPoint(xPos - 10, yPos + 70) << QPoint(xPos - 35, yPos + 50)
//             << QPoint(xPos - 60, yPos + 70) << QPoint(xPos - 50, yPos + 50)
//             << QPoint(xPos - 70, yPos + 25) << QPoint(xPos - 45, yPos + 25);
        painter->drawPolygon(star);
    }
}
