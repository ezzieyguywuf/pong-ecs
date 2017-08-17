#ifndef SimpleCollisionSystem_HEADER
#define SimpleCollisionSystem_HEADER

#include <SimpleECS/ISystem.h>

class SimpleCollisionSystem : public ecs::ISystem_<SimpleCollisionSystem>
{
    public:
        SimpleCollisionSystem(ecs::Manager& aManager);
        void Execute() const override;
};

#endif //SimpleCollisionSystem_HEADER
