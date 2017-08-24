#ifndef EventCollisionSystem_HEADER
#define EventCollisionSystem_HEADER

#include <SimpleECS/ISystem.h>
#include <SimpleECS/Types.h>
#include <Events/IEvent.h>
#include <Events/EventManager.h>

#include <array>

class EventCollisionSystem : public ecs::ISystem_<EventCollisionSystem>
{
    public:
        EventCollisionSystem(ecs::Manager& aManager, Event::EventManager& anEventManager);
        void processMove(const Event::IEvent& anEvent);
        void processBounce(const ecs::Entity collider, const ecs::Entity collidee) const;
        void Execute(float time_step) const override;

    private:
        ecs::Entities colliders;
};

#endif //EventCollisionSystem_HEADER
