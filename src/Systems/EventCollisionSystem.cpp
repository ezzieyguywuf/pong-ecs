#include "EventCollisionSystem.h"
#include <Components/CollidableComponent.h>
#include <Components/PositionComponent.h>
#include <Components/BoundingBoxComponent.h>
#include <Components/BounceComponent.h>
#include <Components/SpeedComponent.h>
#include <Components/WallComponent.h>
#include <Events/Move.h>

#include <functional>


EventCollisionSystem::EventCollisionSystem(ecs::Manager& aManager, Event::EventManager& anEventManager)
    : ecs::ISystem_<EventCollisionSystem>(aManager)
{
    if (ids.empty())
    {
        ids.insert(CollidableComponent::sGetID());
        ids.insert(PositionComponent::sGetID());
        ids.insert(BoundingBoxComponent::sGetID());
    }
    anEventManager.attach<Event::Move>(std::bind(&EventCollisionSystem::processMove, this, std::placeholders::_1));
}

void EventCollisionSystem::processMove(const Event::IEvent& anEvent)
{
    // get list of moved entities
    const Event::Move& moveEvent = static_cast<const Event::Move&>(anEvent);
    ecs::Entity entity = moveEvent.entity;
    if (manager.hasComponent(entity, BoundingBoxComponent::sGetID()) &&
        manager.hasComponent(entity, CollidableComponent::sGetID()))
        colliders.push_back(moveEvent.entity);
}

void EventCollisionSystem::processBounce( const ecs::Entity& collider, const ecs::Entity& collidee) const
{
    if (!manager.hasComponent(collidee, WallComponent::sGetID()))
        return;
    if (manager.hasComponent(collider, SpeedComponent::sGetID())){
        auto& wall  = manager.getComponent<WallComponent>(collidee);
        auto& speed = manager.getComponent<SpeedComponent>(collider);
        if (wall.vert)
            speed.x *= -1;
        else
            speed.y *= -1;
    }
}

void EventCollisionSystem::Execute(float time_step)
{
    // check collidable entities against moved entities
    //for (const ecs::Entity& moved : colliders){
    while (!colliders.empty()){
        const ecs::Entity& moved = colliders.back();
        colliders.pop_back();
        for (const ecs::Entity& collidable : manager.getEntities(this->getComponentIDs())){
            if (moved == collidable)
                continue;
            auto& pos1  = manager.getComponent<PositionComponent>(moved);
            auto& pos2  = manager.getComponent<PositionComponent>(collidable);
            auto& bbox1 = manager.getComponent<BoundingBoxComponent>(moved);
            auto& bbox2 = manager.getComponent<BoundingBoxComponent>(collidable);
            if ((pos1.x <= pos2.x + bbox2.width) &&
                (pos1.x + bbox1.width >= pos2.x) &&
                (pos1.y <= pos2.y + bbox2.height) &&
                (pos1.y + bbox1.height >= pos2.y)){
                if (manager.hasComponent(moved, BounceComponent::sGetID()))
                    this->processBounce(moved, collidable);
                else
                {
                    if (manager.hasComponent(moved, SpeedComponent::sGetID())){
                        auto& speed = manager.getComponent<SpeedComponent>(moved);
                        if (pos1.x <= pos2.x + bbox2.width &&
                            pos1.x >= pos2.x){
                            // collision in x-direction
                            if (speed.x != 0){
                                if (pos1.x > pos2.x)
                                    pos1.x += -1 * (pos1.x - pos2.x)/speed.x;
                                else
                                    pos1.x += -1 * (pos2.x - pos1.x)/speed.x;
                            }
                        }
                        if (pos1.y <= pos2.y + bbox2.height &&
                            pos1.y >= pos2.y){
                            // collision in x-direction
                            if (pos1.y > pos2.y)
                                pos1.y += -1 * (pos1.y - pos2.y)/speed.y;
                            else
                                pos1.y += -1 * (pos2.y - pos1.y)/speed.y;
                        }
                    }
                }
            }
        }
    }
}
