#ifndef LOCKEDCHECKBOXGRID_H
#define LOCKEDCHECKBOXGRID_H

#include "freezablegraphicswidget.h"


class LockedCheckBox;

class LockedCheckBoxGrid : public FreezableGraphicsWidget
{
    Q_OBJECT
public:
    explicit LockedCheckBoxGrid(int width, int height, int checkboxWidth, int checkboxHeight, QWidget *parent = nullptr);
    ~LockedCheckBoxGrid();

    void setBoxChecked(int x, int y, bool state);

private:
    int width;
    int height;
    int checkboxWidth;
    int checkboxHeight;

    LockedCheckBox **boxes;
};

#endif // LOCKEDCHECKBOXGRID_H
