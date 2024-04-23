#include "world.h"
#include "entity/base/entity.h"

#include <QGraphicsView>

namespace game {

World::World(QWidget *parent)
    : QWidget{parent}
    , graphicsView{new QGraphicsView(this)}
{}

World::~World() {
    delete graphicsView;
}

void World::addEntity(entity::base::Entity entity) {
    entities.push_back(entity);
}

}
