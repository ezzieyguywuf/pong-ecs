#ifndef PositionSinkComponent_HEADER
#define PositionSinkComponent_HEADER

#include <SimpleECS/IComponent.h>
#include <SimpleECS/Types.h>

class PositionSinkComponent : public ecs::IComponent_<PositionSinkComponent>
{
    public:
        PositionSinkComponent(ecs::Entity aSource)
            : source(aSource){};

        ecs::Entity source;
};

#endif //PositionSinkComponent_HEADER
