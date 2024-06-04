#ifndef ENTITY_H
#define ENTITY_H

#include <string>

namespace game::entity::base {

class Entity
{
public:
    Entity();

    virtual std::string debugName() = 0;

    template<typename T>
    T* getComponent()
    {
        return dynamic_cast<T*>(this);
    }

    template<typename T>
    bool hasComponent()
    {
        return getComponent<T>() != nullptr;
    }

    int getX() const;
    int getY() const;

protected:
    int x;
    int y;
};

}
#endif // ENTITY_H
