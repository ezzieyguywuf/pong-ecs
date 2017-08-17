#include "PhysicsSystem.h"
#include <Components/PositionComponent.h>
#include <Components/SpeedComponent.h>


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
        ecs::IComponent& temp1 = manager.getComponent(entity, PositionComponent::sGetID());
        PositionComponent& position = static_cast<PositionComponent&>(temp1);
        ecs::IComponent& temp2 = manager.getComponent(entity, SpeedComponent::sGetID());
        SpeedComponent& speed = static_cast<SpeedComponent&>(temp2);
        position.x += speed.x;
        position.y += speed.y;
    }
}
