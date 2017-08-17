#include "PhysicsSystem.h"
#include <Components/PositionComponent.h>
#include <Components/SpeedComponent.h>
#include <Components/TextSinkComponent.h>

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

        if (manager.hasComponent(entity, TextSinkComponent::sGetID()))
        {
            std::stringstream out;
            out << "pos|  x = " << position.x;
            out << ",  y = " << position.y << std::endl;
            out << "spd| vx = " << speed.x;
            out << ", vy = " << speed.y << std::endl;
            TextSinkComponent& text = manager.getComponent<TextSinkComponent>(entity);
            text.text.setString(out.str());
        }
    }
}
