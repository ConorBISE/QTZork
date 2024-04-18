#include "freezablegraphicswidget.h"

#include <QCoreApplication>
#include <QEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

FreezableGraphicsWidget::FreezableGraphicsWidget(QWidget *parent)
    : QWidget{parent}
{
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    setEnabled(true);
}

void FreezableGraphicsWidget::freeze(QImage& image) {
    QGraphicsScene scene;
    QGraphicsView view;

    scene.addWidget(this);
    view.setScene(&scene);
    view.resize(size());
    view.setSceneRect(0, 0, view.contentsRect().width(), view.contentsRect().height());

    QPainter painter(&image);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    scene.render(&painter);
}
