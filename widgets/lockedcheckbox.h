#ifndef LOCKEDCHECKBOX_H
#define LOCKEDCHECKBOX_H

#include <QCheckBox>
#include <QKeyEvent>

namespace widgets {

/*
 * LockedCheckBox
 * A widget that looks identical to an enabled QCheckBox, but ignores all clicks upon it.
 * QCheckBox::setEnabled(false) achieves something similar, but sets the checkbox into
 * a grayed, disabled state.
 */

class LockedCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    LockedCheckBox(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    bool event(QEvent *evt) override;
};
#endif // LOCKEDCHECKBOX_H

}
