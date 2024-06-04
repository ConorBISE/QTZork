#ifndef SPRITE_H
#define SPRITE_H


class QGraphicsItem;
class QGraphicsScene;

namespace game::entity::base {

class Sprite
{
public:
    Sprite();

    virtual void setupSprite(QGraphicsScene *scene) = 0;
    QGraphicsItem *getGraphicsItem();

protected:
    QGraphicsItem *graphicsItem = (QGraphicsItem*)0xdeadbeef;
};

}

#endif // SPRITE_H
