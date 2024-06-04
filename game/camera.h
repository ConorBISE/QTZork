#ifndef CAMERA_H
#define CAMERA_H

#include <QGraphicsItem>
#include <QVector2D>


namespace game {

namespace entity::base { class Entity; }

class Camera
{
public:
    Camera();
    void setTransform(int cx, int cy);
    void addVisualEntity(entity::base::Entity *e);

private:
    std::vector<entity::base::Entity*> visualEntities;
};

}

#endif // CAMERA_H
