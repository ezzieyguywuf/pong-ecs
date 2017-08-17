#ifndef PositionComponent_HEADER
#define PositionComponent_HEADER

#include <SimpleECS/IComponent.h>

class PositionComponent : public ecs::IComponent_<PositionComponent>
{
    public:
        PositionComponent()
            : x(0), y(0){};
        PositionComponent(float ax, float ay)
            : x(ax), y(ay){};
        ~PositionComponent(){};

        float x;
        float y;
};

#endif //PositionComponent_HEADER
