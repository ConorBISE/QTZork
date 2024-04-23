#ifndef LEVEL_H
#define LEVEL_H

#include <istream>
#include <vector>

namespace game {

struct Block
{
    unsigned int x;
    unsigned int y;
    unsigned int width;
    unsigned int height;
};

struct Level
{
    std::vector<Block> backgroundBlocks;
};

std::istream& operator>>(std::istream& in, Level& l);

}

#endif // LEVEL_H
