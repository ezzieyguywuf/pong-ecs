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
    //NOTE: time_step is in microseconds. act accordingly
    for (auto& entity : manager.getEntities(this->getComponentIDs()))
    {
        PositionComponent& position = manager.getComponent<PositionComponent>(entity);
        SpeedComponent& speed = manager.getComponent<SpeedComponent>(entity);

        position.x += speed.x * time_step/1000000.0;
        position.y += speed.y * time_step/1000000.0;
        if (speed.x !=0 || speed.y != 0)
            eventManager.broadcast(Event::Move(entity));
    }
}
