#include "level.h"
#include "../io/jsonobject.h"

namespace game {


const std::vector<Block>& Level::getBackgroundBlocks() const {
    return backgroundBlocks;
};

void Level::getBoundingBlock(Block &boundingBlock) const {
    boundingBlock.setX(0);
    boundingBlock.setY(0);
    boundingBlock.setWidth(0);
    boundingBlock.setHeight(0);

    for (Block backgroundBlock : backgroundBlocks) {
        if (backgroundBlock.getX() < boundingBlock.getX())
            boundingBlock.setX(backgroundBlock.getX());

        if (backgroundBlock.getY() < boundingBlock.getY())
            boundingBlock.setY(backgroundBlock.getY());

        if ((backgroundBlock.getX() + backgroundBlock.getWidth()) > (boundingBlock.getX() + boundingBlock.getWidth()))
            boundingBlock.setWidth(backgroundBlock.getX() + backgroundBlock.getWidth() - boundingBlock.getX());

        if ((backgroundBlock.getY() + backgroundBlock.getHeight()) > (boundingBlock.getY() + boundingBlock.getHeight()))
            boundingBlock.setHeight(backgroundBlock.getY() + backgroundBlock.getHeight() - boundingBlock.getY());
    }
}

QDebug operator<<(QDebug debug, const Block &l) {
    debug << "Block { x:" << l.getX() << "y:" << l.getY() << "width:" << l.getWidth() << "height:" << l.getHeight() << "polarity:" << l.getPolarity() << "}";
    return debug;
}

std::istream& operator>>(std::istream &in, Level &l) {
    io::JsonObject *o = new io::JsonObject;
    in >> *o;

    for (io::JsonObject *jsonBlock : *o->getValObject()->get("backgroundBlocks")->getValList()) {
        auto jsonBlockObj = jsonBlock->getValObject();

        Block block(
            jsonBlockObj->get("x")->getValNum(),
            jsonBlockObj->get("y")->getValNum(),
            (unsigned int) jsonBlockObj->get("width")->getValNum(),
            (unsigned int) jsonBlockObj->get("height")->getValNum(),
            jsonBlockObj->get("polarity")->getValBool()
        );

        l.backgroundBlocks.push_back(block);
    }

    return in;
}

}
