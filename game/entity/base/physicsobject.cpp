#include "physicsobject.h"
#include <cstdlib>

namespace game::entity::base {

PhysicsObject::PhysicsObject() {
    vx = 0;
    vy = 0;
}

void PhysicsObject::update() {
    vx *= .95;
    vy *= .95;

    if (std::abs(vx) > 10)
        vx = ((vx > 0) - (vx < 0)) * 10;

    if (std::abs(vy) > 10)
        vy = ((vy > 0) - (vy < 0)) * 10;
};


}
