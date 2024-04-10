#include "qtzork.h"
#include "widgets/lockedcheckboxgrid.h"

#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
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

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::ItemIndexMethod::NoIndex);

    QGraphicsView *view = new QGraphicsView(this);
    view->resize(size());
    view->setSceneRect(0, 0, view->contentsRect().width(), view->contentsRect().height());

    w = scene->addWidget(grid);
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

    pos = 325;
    vel = 10;
}

QTZork::~QTZork() {
    delete grid;
}

void QTZork::update() {
    vel += -(pos - 325) * .1 * .1;
    pos += vel * .1;
    w->setX(pos);
}
