#include "InputHandlerSystem.h"
#include <Components/MovableComponent.h>
#include <Components/SpeedComponent.h>
#include <SFML/Window.hpp>
#include <Events/Input.h>
#include <Events/Event.h>
#include <set>
#include <memory>

using Events = std::set<sf::Keyboard::Key>;

InputHandlerSystem::InputHandlerSystem(ecs::Manager& aManager, Event::EventManager& anEventManager)
    : ecs::ISystem_<InputHandlerSystem>(aManager),
      eventManager(anEventManager){
    if (ids.empty())
    {
        ids.insert(SpeedComponent::sGetID());
        ids.insert(MovableComponent::sGetID());
    }
    eventManager.attach<Event::Input>(
            std::bind(&InputHandlerSystem::processEvent, 
                      this, 
                      std::placeholders::_1));
}

void InputHandlerSystem::processEvent(const Event::IEvent& anEvent)
{
    const Event::Input& inpEvent = static_cast<const Event::Input&>(anEvent);
    eventMap[inpEvent.key] = inpEvent.pressed;
}

void InputHandlerSystem::Execute(float time_step) const
{
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        SpeedComponent& speed = manager.getComponent<SpeedComponent>(entity);
        MovableComponent& move = manager.getComponent<MovableComponent>(entity);

        if (eventMap.find(move.up) != eventMap.end()){
            if (eventMap.at(move.up) == true && speed.y > -10){
                speed.y -= 1;
            }
            else if (eventMap.at(move.up) == false && speed.y < 0){
                speed.y += 1;
            }
        }
        if (eventMap.find(move.down) != eventMap.end()){
            if (eventMap.at(move.down) && speed.y < 10){
                speed.y += 1;
            }
            else if (eventMap.at(move.down) == false && speed.y > 0){
                speed.y -= 1;
            }
        }
        if (eventMap.find(move.left) != eventMap.end()){
            if (eventMap.at(move.left) && speed.x > -10){
                speed.x -= 1;
            }
            else if (eventMap.at(move.left) == false && speed.x < 0){
                speed.x += 1;
            }
        }
        if (eventMap.find(move.right) != eventMap.end()){
            if (eventMap.at(move.right) && speed.x < 10){
                speed.x += 1;
            }
            else if (eventMap.at(move.right) == false && speed.x > 0){
                speed.x -= 1;
            }
        }
    }
}

