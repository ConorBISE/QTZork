#include "player.h"
#include "../../util/logging.h"

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QRadioButton>

#define KEY_W 87
#define KEY_A 65
#define KEY_S 83
#define KEY_D 68

namespace game::entity {

Player::Player()
{
    LOGGER->logObj("Creating Player");

    x = y = 150;
    direction.clearHorizontal();
    direction.clearVertical();
}

void Player::setupSprite(QGraphicsScene *scene) {
    graphicsItem = (QGraphicsItem*)scene->addEllipse(getX(), getY(), 10, 10, QPen(QColor(0, 0, 0, 0)), QBrush("#0089fa"));
    graphicsItem->setPos(10, 10);
}

void Player::handleKeyUp(int key) {
    if (key == KEY_W || key == KEY_S)
        direction.clearVertical();

    if (key == KEY_A || key == KEY_D)
        direction.clearHorizontal();
};

void Player::handleKeyDown(int key) {
    if (key == KEY_W) {
        direction.setUp();
    } else if (key == KEY_A) {
        direction.setLeft();
    } else if (key == KEY_S) {
        direction.setDown();
    } else if (key == KEY_D) {
        direction.setRight();
    }
};

void Player::update() {
    PhysicsObject::update();

    vx += direction.getX() * .5;
    vy += direction.getY() * .5;

    x += vx * .5;
    y += vy * .5;

    graphicsItem->setPos(x, y);
};

}
