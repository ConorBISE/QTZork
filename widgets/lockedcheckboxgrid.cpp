#include "lockedcheckboxgrid.h"

#include "lockedcheckbox.h"

#include <QRadioButton>

namespace widgets {

LockedCheckBoxGrid::LockedCheckBoxGrid(int width, int height, int checkboxWidth, int checkboxHeight, QWidget *parent)
    : FreezableGraphicsWidget{parent}
    , width{width}
    , height{height}
    , checkboxWidth{checkboxWidth}
    , checkboxHeight{checkboxHeight}
{
    boxes = new LockedCheckBox*[width * height];

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            LockedCheckBox *box = new LockedCheckBox(this);

            box->setParent(this);
            box->resize(checkboxWidth, checkboxHeight);
            box->move(checkboxWidth * i, checkboxHeight * j);

            boxes[i * width + j] = box;
        }
    }

    resize(checkboxWidth * width, checkboxHeight * height);
}

LockedCheckBoxGrid::~LockedCheckBoxGrid() {
    for (int i = 0; i < width * height; i++) {
        delete boxes[i];
    }

    delete boxes;
}

void LockedCheckBoxGrid::setBoxChecked(int x, int y, bool state) {
     if (x >= 0 && x < width && y >= 0 && y < height)
         boxes[x * width + y]->setCheckState(state ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
}

void LockedCheckBoxGrid::setRectChecked(int x, int y, unsigned int width, unsigned int height, bool state) {
    for (int i = x; i < x + width; i++)
        for (int j = y; j < y + height; j++)
            setBoxChecked(i, j, state);
}

int LockedCheckBoxGrid::getWidth() const
{
    return width;
}

int LockedCheckBoxGrid::getHeight() const
{
    return height;
};

int LockedCheckBoxGrid::getImageWidth() const
{
    return width * checkboxWidth;
}

int LockedCheckBoxGrid::getImageHeight() const
{
    return height * checkboxHeight;
};

}
