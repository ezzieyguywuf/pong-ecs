#ifndef Move_HEADER
#define Move_HEADER

#include "IEvent.h"
#include <SFML/Window.hpp>
#include <SimpleECS/Types.h>

namespace Event{
    class Move : public IEvent
    {
        public:
            Move(ecs::Entity anEntity)
                : entity(anEntity){};

            ecs::Entity entity;
    };
}

#endif //Move_HEADER
