#ifndef QTZORK_H
#define QTZORK_H

#include "game/camera.h"
#include <QKeyEvent>
#include <QMainWindow>

namespace game {

namespace entity { class Player; }

class World;

class QTZork : public QMainWindow
{
    Q_OBJECT

public:
    QTZork(QWidget *parent = nullptr);
    ~QTZork();

    void update();

private:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    game::Camera *camera;
    game::World *world;
    entity::Player *player;
};

}

#endif // QTZORK_H
