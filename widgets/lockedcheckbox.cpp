#include "lockedcheckbox.h"

#include <QStyleOptionButton>
#include <QStylePainter>
#include <qdrawutil.h>

LockedCheckBox::LockedCheckBox(QWidget *parent)
    : QCheckBox(parent) {}

// When we receive a mouse click or key press - just ignore it.
void LockedCheckBox::mousePressEvent(QMouseEvent *event) {
    event->ignore();
};

void LockedCheckBox::keyPressEvent(QKeyEvent *event) {
    event->ignore();
};

bool LockedCheckBox::event(QEvent *evt) {
    return QCheckBox::event(evt);
}
