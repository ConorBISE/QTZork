#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "base/entity.h"
#include "base/sprite.h"


namespace widgets { class LockedCheckBoxGrid; }
namespace game { class Level; }

namespace game::entity {

class Background : public base::Entity, public base::Sprite
{
public:
    Background(const Level &level);
    std::string debugName() override { return "Background"; };
    void setupSprite(QGraphicsScene *scene) override;

private:
    widgets::LockedCheckBoxGrid *widget;
};

}

#endif // BACKGROUND_H
