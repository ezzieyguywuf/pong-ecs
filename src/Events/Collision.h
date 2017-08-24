#ifndef Collision_HEADER
#define Collision_HEADER

#include "IEvent.h"
#include <SimpleECS/Types.h>
#include <SFML/Window.hpp>

namespace Event{
    class Collision : public IEvent
    {
        public:
            Collision(const ecs::Entity aCollider, const ecs::Entity aCollidee)
                : collider(aCollider),
                  collidee(aCollidee){};

            // `collider` is the entity that moved into another entity
            const ecs::Entity collider;
            // `collidee` is the entity that was moved into
            const ecs::Entity collidee;
    };
}

#endif //Collision_HEADER

