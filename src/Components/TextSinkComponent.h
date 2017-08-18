#ifndef TextSinkComponent_HEADER
#define TextSinkComponent_HEADER

#include <SimpleECS/Types.h>

#include <SimpleECS/IComponent.h>

class TextSinkComponent : public ecs::IComponent_<TextSinkComponent>
{
    public:
        TextSinkComponent(ecs::Entity aSink)
            : entity(aSink){};

        ecs::Entity entity;
};

#endif //TextSinkComponent_HEADER
