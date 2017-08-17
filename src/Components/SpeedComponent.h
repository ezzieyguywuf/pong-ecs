#ifndef SpeedComponent_HEADER
#define SpeedComponent_HEADER

#include <SimpleECS/IComponent.h>

class SpeedComponent : public ecs::IComponent_<SpeedComponent>
{
    public:
        SpeedComponent()
            : x(0), y(0){};
        SpeedComponent(float ax, float ay)
            : x(ax), y(ay){};
        ~SpeedComponent(){};

        float x;
        float y;
};

#endif //SpeedComponent_HEADER
