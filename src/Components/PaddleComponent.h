#ifndef PaddleComponent_HEADER
#define PaddleComponent_HEADER

#include <SimpleECS/IComponent.h>

class PaddleComponent : public ecs::IComponent_<PaddleComponent>
{
    public:
        PaddleComponent(){};
        ~PaddleComponent(){};
};

#endif //PaddleComponent_HEADER
