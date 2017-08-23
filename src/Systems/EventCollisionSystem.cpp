#include "EventCollisionSystem.h"
#include <Components/CollidableComponent.h>
#include <Components/BoundingBoxComponent.h>
#include <Components/BounceComponent.h>
#include <Components/SpeedComponent.h>
#include <Events/Move.h>

#include <functional>


EventCollisionSystem::EventCollisionSystem(ecs::Manager& aManager, Event::EventManager& anEventManager)
    : ecs::ISystem_<EventCollisionSystem>(aManager)
{
    if (ids.empty())
    {
        ids.insert(CollidableComponent::sGetID());
        ids.insert(BoundingBoxComponent::sGetID());
    }
    anEventManager.attach<Event::Move>(std::bind(&EventCollisionSystem::processEvent, this, std::placeholders::_1));
}

void EventCollisionSystem::processEvent(const Event::IEvent& anEvent)
{
    const Event::Move& moveEvent = static_cast<const Event::Move&>(anEvent);
    colliders.push_back(moveEvent.entity);
}

void EventCollisionSystem::Execute(float time_step) const
{
    // emit collision events

}
