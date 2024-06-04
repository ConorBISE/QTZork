#ifndef PLAYER_H
#define PLAYER_H

#include "base/entity.h"
#include "base/physicsobject.h"
#include "base/sprite.h"
#include "../direction.h"

class QRadioButton;

namespace game::entity {

class Player: public base::Entity, public base::Sprite, public base::PhysicsObject
{
public:
    Player();
    std::string debugName() override { return "Player"; };

    void setupSprite(QGraphicsScene *scene) override;
    void handleKeyUp(int key);
    void handleKeyDown(int key);
    void update() override;

private:
    Direction direction;

};

}
#endif // PLAYER_H
