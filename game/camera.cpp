#include "camera.h"
#include "entity/base/entity.h"
#include "entity/base/sprite.h"

#include <QGraphicsScene>
#include <QGraphicsItem>

namespace game {

Camera::Camera()
{}

void Camera::addVisualEntity(entity::base::Entity *e) {
    visualEntities.push_back(e);
}

void Camera::setTransform(int cx, int cy)
{
    for (auto* e : visualEntities) {
        auto sprite = e->getComponent<entity::base::Sprite>();
        auto gi = sprite->getGraphicsItem();
        gi->setPos(e->getX() + cx, e->getY() + cy);
    }
}

}
