#ifndef MovableComponent_HEADER
#define MovableComponent_HEADER

#include <SimpleECS/IComponent.h>
#include <Utilities/Vector.h>

class MovableComponent : public ecs::IComponent_<MovableComponent>
{
    public:
        MovableComponent();
        MovableComponent(Vector loc);
        MovableComponent(Vector loc, Vector speed);
        ~MovableComponent(){};

        Vector location;
        Vector speed;
};

#endif //MovableComponent_HEADER
