#include "mainwindow.h"
#include "figure.h"

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    resize(400, 300);

    scene = new QGraphicsScene();
    setScene(scene);
}

MainWindow::~MainWindow()
{
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->pos().x();
    int y = event->pos().y();

    if (event->button() == Qt::LeftButton) {
        scene->addItem(new Figure(x, y));
    } else if (event->button() == Qt::RightButton) {
        QGraphicsItem *item = scene->itemAt(x, y, QTransform());
        scene->removeItem(item);
    }
}

