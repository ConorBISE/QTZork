#include "qtzork.h"
#include "game/level.h"

QTZork::QTZork(QWidget *parent)
    : QMainWindow(parent)
{
    game::Level l {
        .backgroundBlocks = {
            game::Block {.x = 0, .y = 0, .width = 20, .height = 20}
        }
    };

}

QTZork::~QTZork() {

}
