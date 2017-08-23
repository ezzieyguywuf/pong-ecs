#ifndef PhysicsSystem_HEADER
#define PhysicsSystem_HEADER

#include <SimpleECS/Types.h>
#include <SimpleECS/Manager.h>
#include <SimpleECS/ISystem.h>
#include <Events/EventManager.h>

class PhysicsSystem : public ecs::ISystem_<PhysicsSystem>
{
    public:
        PhysicsSystem(ecs::Manager& aManager, Event::EventManager& anEventManager);
        void Execute(float time_step) const override;

    private:
        Event::EventManager& eventManager;

};

#endif //PhysicsSystem_HEADER
