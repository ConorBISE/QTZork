#include "qtzork.h"
#include "game/entity/background.h"
#include "game/entity/player.h"
#include "game/level.h"
#include "game/world.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QRadioButton>
#include <QTimer>

#include <fstream>

namespace game {

QTZork::QTZork(QWidget *parent)
    : QMainWindow(parent)
    , camera{new Camera}
    , world{new game::World(camera, this)}
{
    std::ifstream in("level.json");
    game::Level level;
    in >> level;

    entity::Background *b = new entity::Background(level);
    player = new entity::Player;

    world->addEntity(b);
    world->addEntity(player);

    setFixedSize(world->size());

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &QTZork::update);
    timer->start(15);
}

void QTZork::update() {
    player->update();
}

void QTZork::keyPressEvent(QKeyEvent *event) {
    if (event->isAutoRepeat())
        return;

    player->handleKeyDown(event->key());
};

void QTZork::keyReleaseEvent(QKeyEvent *event) {
    if (event->isAutoRepeat())
        return;

    player->handleKeyUp(event->key());
};

QTZork::~QTZork() {

}

}
