#ifndef CollidableComponent_HEADER
#define CollidableComponent_HEADER

#include <SimpleECS/IComponent.h>

class CollidableComponent : public ecs::IComponent_<CollidableComponent>
{
    public:
        CollidableComponent()
            : hasCollided(false){};

        bool hasCollided;
};

#endif //CollidableComponent_HEADER
