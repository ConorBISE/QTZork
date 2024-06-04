#include "direction.h"

namespace game {

Direction::Direction() {
    x = 0;
    y = 0;
}

void Direction::setLeft() {
    x = -1;
};

void Direction::setRight() {
    x = 1;
};

void Direction::clearHorizontal() {
    x = 0;
};

void Direction::setUp() {
    y = -1;
};

void Direction::setDown() {
    y = 1;
};

void Direction::clearVertical() {
    y = 0;
};

signed char Direction::getX() {
    return x;
};

signed char Direction::getY() {
    return y;
};

}
