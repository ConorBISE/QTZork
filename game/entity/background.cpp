#include "background.h"
#include "../../widgets/lockedcheckboxgrid.h"
#include "../level.h"
#include "../../util/logging.h"

#include <QGraphicsItem>
#include <QGraphicsScene>

namespace game::entity {

Background::Background(const Level &level)
{
    LOGGER->logObj("Creating Background");

    game::Block boundingBlock = game::Block {0, 0, 0, 0};
    level.getBoundingBlock(boundingBlock);

    widget = new widgets::LockedCheckBoxGrid(boundingBlock.getWidth(), boundingBlock.getHeight(), 15, 15);

    for (Block backgroundBlock : level.getBackgroundBlocks()) {
        widget->setRectChecked(backgroundBlock.getX(),
                               backgroundBlock.getY(),
                               backgroundBlock.getWidth(),
                               backgroundBlock.getHeight(),
                               backgroundBlock.getPolarity());
    }
}

void Background::setupSprite(QGraphicsScene *scene) {
    QImage frozenImage = QImage(widget->getImageWidth(), widget->getImageHeight(), QImage::Format_ARGB32);
    widget->freeze(frozenImage);

    graphicsItem = new QGraphicsPixmapItem(QPixmap::fromImage(frozenImage));
    scene->addItem(graphicsItem);
}

}
