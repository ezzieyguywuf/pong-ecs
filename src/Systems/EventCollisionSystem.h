#ifndef EventCollisionSystem_HEADER
#define EventCollisionSystem_HEADER

#include <SimpleECS/ISystem.h>
#include <SimpleECS/Types.h>
#include <Events/IEvent.h>
#include <Events/EventManager.h>

class EventCollisionSystem : public ecs::ISystem_<EventCollisionSystem>
{
    public:
        EventCollisionSystem(ecs::Manager& aManager, Event::EventManager& anEventManager);
        void processEvent(const Event::IEvent& anEvent);
        void Execute(float time_step) const override;

    private:
        ecs::Entities colliders;
};

#endif //EventCollisionSystem_HEADER
