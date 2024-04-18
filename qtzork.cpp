#include "qtzork.h"
#include "widgets/lockedcheckboxgrid.h"

#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QOpenGLWidget>
#include <QRadioButton>
#include <QTimer>

QTZork::QTZork(QWidget *parent)
    : QMainWindow(parent)
{
    grid = new LockedCheckBoxGrid(50, 50, 15, 15);
    resize(grid->size());

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            grid->setBoxChecked(i, j, true);
        }
    }

    for (int i = 20; i < 30; i++) {
        for (int j = 20; j < 30; j++) {
            grid->setBoxChecked(i, j, false);
        }
    }

    QImage image(grid->size(), QImage::Format_ARGB32_Premultiplied);
    grid->freeze(image);
    image.save("out.png");

    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(this);

    view->resize(image.size());
    view->setSceneRect(0, 0, view->contentsRect().width(), view->contentsRect().height());

    w = scene->addPixmap(QPixmap::fromImage(image));
    w->setTransformationMode(Qt::SmoothTransformation);
    w->setPos(0, 0);

    view->setScene(scene);

    radio = new QRadioButton();
    radio->setStyleSheet("background: transparent;");
    radioProxy = scene->addWidget(radio);
    radioProxy->setPos(325, 325);

    QTimer *timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, &QTimer::timeout, this, &QTZork::update);
    timer->start();

    pos = 0;
    vel = 10;
}

QTZork::~QTZork() {

}

void QTZork::update() {
    vel += -(pos - 325) * .01;
    pos += vel * .01;
    w->setX(pos);
}
