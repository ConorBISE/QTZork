#include "sprite.h"
#include "../../../util/logging.h"

namespace game::entity::base {
    Sprite::Sprite() {
        LOGGER->logObj("Creating Sprite");
    }

    QGraphicsItem *Sprite::getGraphicsItem() {
        return graphicsItem;
    };
}
