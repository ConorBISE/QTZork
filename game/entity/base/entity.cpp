#include "entity.h"
#include "../../../util/logging.h"

namespace game::entity::base {
    Entity::Entity() : x(0), y(0) {
        LOGGER->logObj("Creating Entity");
    }

    int Entity::getX() const {
        return x;
    }

    int Entity::getY() const {
        return y;
    }
}
