#ifndef QTZORK_H
#define QTZORK_H

#include <QKeyEvent>
#include <QMainWindow>

class QGraphicsPixmapItem;
class QRadioButton;
class LockedCheckBoxGrid;

class QTZork : public QMainWindow
{
    Q_OBJECT

public:
    QTZork(QWidget *parent = nullptr);
    ~QTZork();

    void update();

private:
    LockedCheckBoxGrid *grid;
    QRadioButton *radio;
    QGraphicsProxyWidget *radioProxy;
    QGraphicsPixmapItem *w;

    float pos;
    float vel;
};
#endif // QTZORK_H
