#ifndef FREEZABLEGRAPHICSWIDGET_H
#define FREEZABLEGRAPHICSWIDGET_H

#include <QWidget>

namespace widgets {

class FreezableGraphicsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FreezableGraphicsWidget(QWidget *parent = nullptr);
    void freeze(QImage& image);
};

}

#endif // FREEZABLEGRAPHICSWIDGET_H
