#ifndef DisplayTextComponent_HEADER
#define DisplayTextComponent_HEADER

#include <SimpleECS/IComponent.h>
#include <SimpleECS/Types.h>

class DisplayTextComponent : public ecs::IComponent_<DisplayTextComponent>
{
    public:
        DisplayTextComponent(Entity aTarget, Entity aSource)
            : target(aTarget), source(aSource){};
        ~DisplayTextComponent(){};

        Entity target;
        Entity source;
};

#endif //DisplayTextComponent_HEADER
