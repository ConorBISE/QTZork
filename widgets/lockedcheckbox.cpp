#include "lockedcheckbox.h"

LockedCheckBox::LockedCheckBox(QWidget *parent)
    : QCheckBox(parent) {}

// When we receive a mouse click or key press - just ignore it.
void LockedCheckBox::mousePressEvent(QMouseEvent *event) {
    event->ignore();
};

void LockedCheckBox::keyPressEvent(QKeyEvent *event) {
    event->ignore();
};
