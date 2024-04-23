#ifndef QTZORK_H
#define QTZORK_H

#include <QKeyEvent>
#include <QMainWindow>

namespace game { class World; }

class QTZork : public QMainWindow
{
    Q_OBJECT

public:
    QTZork(QWidget *parent = nullptr);
    ~QTZork();

    void update();

private:
    game::World *world;
};
#endif // QTZORK_H
