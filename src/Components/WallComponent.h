#ifndef WallComponent_HEADER
#define WallComponent_HEADER

#include <SimpleECS/IComponent.h>

class WallComponent : public ecs::IComponent_<WallComponent>
{
    public:
        WallComponent(bool isvert=true)
            : vert(isvert){};

        bool vert;
};

#endif //WallComponent_HEADER

