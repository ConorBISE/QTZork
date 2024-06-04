#ifndef LOCKEDCHECKBOXGRID_H
#define LOCKEDCHECKBOXGRID_H

#include "freezablegraphicswidget.h"



namespace widgets {

class LockedCheckBox;

class LockedCheckBoxGrid : public FreezableGraphicsWidget
{
    Q_OBJECT
public:
    explicit LockedCheckBoxGrid(int width, int height, int checkboxWidth, int checkboxHeight, QWidget *parent = nullptr);
    ~LockedCheckBoxGrid();

    void setBoxChecked(int x, int y, bool state);
    void setRectChecked(int x, int y, unsigned int width, unsigned int height, bool state);

    int getWidth() const;
    int getHeight() const;

    int getImageWidth() const;
    int getImageHeight() const;

private:
    int width;
    int height;
    int checkboxWidth;
    int checkboxHeight;

    LockedCheckBox **boxes;
};

}

#endif // LOCKEDCHECKBOXGRID_H
