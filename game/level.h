#ifndef LEVEL_H
#define LEVEL_H

#include <QDebug>
#include <vector>

namespace game {

class Block
{
public:
    Block(int x, int y, unsigned int width, unsigned int height, bool polarity=true)
        : x(x), y(y), width(width), height(height), polarity(polarity) {}

    void setX(int x) { this->x = x; };
    void setY(int y) { this->y = y; };
    void setWidth(unsigned int width) { this->width = width; };
    void setHeight(unsigned int height) { this->height = height; };
    void setPolarity(bool polarity) { this->polarity = polarity; };

    int getX() const { return x; };
    int getY() const { return y; };
    unsigned int getWidth() const { return width; };
    unsigned int getHeight() const { return height; };
    bool getPolarity() const { return polarity; };

private:
    int x;
    int y;
    unsigned int width;
    unsigned int height;
    bool polarity = true;
};

class Level
{
public:
    const std::vector<Block>& getBackgroundBlocks() const;
    void getBoundingBlock(Block &boundingBlock) const;

    friend std::istream& operator>>(std::istream &in, Level &l);

private:
    std::vector<Block> backgroundBlocks;
};

QDebug operator<<(QDebug debug, const Block &l);
std::istream& operator>>(std::istream &in, Level &l);

}

#endif // LEVEL_H
