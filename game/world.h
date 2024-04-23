#ifndef WORLD_H
#define WORLD_H

#include <QWidget>

class QGraphicsView;

namespace entity::base {
class Entity;
}

namespace game {

class World : public QWidget
{
    Q_OBJECT
public:
    explicit World(QWidget *parent = nullptr);
    ~World();

    void addEntity(entity::base::Entity entity);

private:
    std::vector<entity::base::Entity> entities;
    QGraphicsView *graphicsView;
};

}

#endif // WORLD_H
