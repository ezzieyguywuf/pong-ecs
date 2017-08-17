#ifndef MovableComponent_HEADER
#define MovableComponent_HEADER

#include <SimpleECS/IComponent.h>
#include <Utilities/Vector.h>

class MovableComponent : public ecs::IComponent_<MovableComponent>
{
    public:
        MovableComponent();
        MovableComponent(Vector loc)
            : location(loc),
              speed(Vector(0,0)){};
        MovableComponent(Vector loc, Vector aSpeed)
            : location(loc),
              speed(aSpeed){};
        ~MovableComponent(){};

        Vector location;
        Vector speed;
};

#endif //MovableComponent_HEADER
