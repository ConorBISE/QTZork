#include "world.h"
#include "camera.h"
#include "entity/base/entity.h"
#include "entity/base/sprite.h"

#include <QGraphicsView>
#include <QRadioButton>

namespace game {

World::World(Camera *camera, QWidget *parent)
    : QWidget{parent}
    , camera{camera}
    , graphicsScene{new QGraphicsScene}
    , graphicsView{new QGraphicsView(graphicsScene, this)}
{
    graphicsView->resize(15 * 50, 15 * 50);
    graphicsView->setSceneRect(graphicsView->contentsRect());
    resize(graphicsView->size());
}

World::~World() {
    delete graphicsView;
}

void World::addEntity(entity::base::Entity *entity) {
    qDebug() << "Adding entity" << entity->debugName() << "to world\n";
    entities.push_back(entity);

    if (auto sprite = entity->getComponent<entity::base::Sprite>(); sprite != nullptr) {
        sprite->setupSprite(graphicsScene);
        camera->addVisualEntity(entity);
    }
}

}
