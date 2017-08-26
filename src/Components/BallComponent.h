#ifndef BallComponent_HEADER
#define BallComponent_HEADER

#include <SimpleECS/IComponent.h>

class BallComponent : public ecs::IComponent_<BallComponent>
{
    public:
        BallComponent(){};
        ~BallComponent(){};
};

#endif //BallComponent_HEADER
