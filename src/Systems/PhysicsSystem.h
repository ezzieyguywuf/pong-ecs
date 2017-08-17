#ifndef PhysicsSystem_HEADER
#define PhysicsSystem_HEADER

#include <SimpleECS/Manager.h>
#include <SimpleECS/ISystem.h>

class PhysicsSystem : public ecs::ISystem_<PhysicsSystem>
{
    public:
        PhysicsSystem(ecs::Manager& aManager);
        void Execute() const override;
};

#endif //PhysicsSystem_HEADER
