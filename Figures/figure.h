#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Figure(int x, int y, QObject *parent = nullptr);

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int xPos;
    int yPos;

    enum Geometry{RECTANGLE, ELLIPS, STAR};
    Geometry geometry;
    static int figureCounter;
};

#endif // FIGURE_H
