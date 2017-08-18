#include "PhysicsSystem.h"
#include <Components/PositionComponent.h>
#include <Components/SpeedComponent.h>

#include <sstream>


PhysicsSystem::PhysicsSystem(ecs::Manager& aManager)
    : ecs::ISystem_<PhysicsSystem>(aManager) {
    if (ids.empty())
    {
        ids.insert(PositionComponent::sGetID());
        ids.insert(SpeedComponent::sGetID());
    }
}

void PhysicsSystem::Execute() const
{
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        PositionComponent& position = manager.getComponent<PositionComponent>(entity);
        SpeedComponent& speed = manager.getComponent<SpeedComponent>(entity);

        position.x += speed.x;
        position.y += speed.y;
    }
}
