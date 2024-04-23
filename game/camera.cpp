#include "camera.h"

namespace game {

QVector2D Camera::transform(const QVector2D p) const {
    return (p * zoom) + center;
};

}
