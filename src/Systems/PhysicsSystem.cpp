#include "PhysicsSystem.h"
#include <Components/PositionComponent.h>
#include <Components/SpeedComponent.h>
#include <Components/BoundingBoxComponent.h>
#include <Events/Move.h>

#include <sstream>


PhysicsSystem::PhysicsSystem(ecs::Manager& aManager, Event::EventManager& anEventManager)
    : ecs::ISystem_<PhysicsSystem>(aManager),
      eventManager(anEventManager)
{
    if (ids.empty())
    {
        ids.insert(PositionComponent::sGetID());
        ids.insert(SpeedComponent::sGetID());
    }
}

void PhysicsSystem::Execute(float time_step)
{
    for (auto& entity : manager.getEntities(this->getComponentIDs()))
    {
        PositionComponent& position = manager.getComponent<PositionComponent>(entity);
        SpeedComponent& speed = manager.getComponent<SpeedComponent>(entity);

        position.x += speed.x ;//* time_step;
        position.y += speed.y ;//* time_step;
        if (speed.x !=0 || speed.y != 0)
            eventManager.broadcast(Event::Move(entity));
    }
}
