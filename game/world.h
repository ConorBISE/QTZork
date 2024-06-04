#ifndef WORLD_H
#define WORLD_H

#include <QWidget>

class QGraphicsView;
class QGraphicsScene;

namespace game {

class Camera;

namespace entity::base { class Entity; }

class World : public QWidget
{
    Q_OBJECT
public:
    explicit World(Camera *camera, QWidget *parent = nullptr);
    ~World();

    void addEntity(entity::base::Entity *entity);

private:
    Camera *camera;
    std::vector<entity::base::Entity *> entities;
    QGraphicsScene *graphicsScene;
    QGraphicsView *graphicsView;
};

}

#endif // WORLD_H
