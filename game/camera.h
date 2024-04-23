#ifndef CAMERA_H
#define CAMERA_H

#include <QVector2D>

namespace game {

struct Camera
{
public:
    QVector2D center;
    float zoom = 1;

    QVector2D transform(const QVector2D p) const;
};

}

#endif // CAMERA_H
