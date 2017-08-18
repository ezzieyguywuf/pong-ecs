#ifndef TextSourceComponent_HEADER
#define TextSourceComponent_HEADER

#include <SimpleECS/Types.h>

#include <SimpleECS/IComponent.h>

class TextSourceComponent : public ecs::IComponent_<TextSourceComponent>
{
    public:
        TextSourceComponent(ecs::Entity aSource)
            : entity(aSource){};

        ecs::Entity entity;
};

#endif //TextSourceComponent_HEADER
