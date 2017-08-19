#include "InputHandlerSystem.h"
#include <Components/MovableComponent.h>
#include <Components/PositionComponent.h>
#include <SFML/Window.hpp>
#include <set>

using Events = std::set<sf::Keyboard::Key>;

InputHandlerSystem::InputHandlerSystem(ecs::Manager& aManager, const Events& aEvents)
    : ecs::ISystem_<InputHandlerSystem>(aManager),
      events(aEvents){
    if (ids.empty())
    {
        ids.insert(PositionComponent::sGetID());
        ids.insert(MovableComponent::sGetID());
    }
}

void InputHandlerSystem::Execute(unsigned int time_step) const
{
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        PositionComponent& pos = manager.getComponent<PositionComponent>(entity);
        MovableComponent& move = manager.getComponent<MovableComponent>(entity);

        if (events.find(move.up) != events.end())
            pos.y -= 10;
        if (events.find(move.down) != events.end())
            pos.y += 10;
        if (events.find(move.left) != events.end())
            pos.x -= 10;
        if (events.find(move.right) != events.end())
            pos.x += 10;
    }
}

