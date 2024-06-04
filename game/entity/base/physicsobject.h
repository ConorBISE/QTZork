#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

namespace game::entity::base {

class PhysicsObject
{
public:
    PhysicsObject();
    virtual void update();

protected:
    float vx;
    float vy;
};

}

#endif // PHYSICSOBJECT_H
