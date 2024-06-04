#ifndef DIRECTION_H
#define DIRECTION_H

namespace game {

class Direction
{
public:
    Direction();

    void setLeft();
    void setRight();
    void clearHorizontal();

    void setUp();
    void setDown();
    void clearVertical();

    signed char getX();
    signed char getY();

private:
    signed char x: 2;
    signed char y: 2;
};

}

#endif // DIRECTION_H

