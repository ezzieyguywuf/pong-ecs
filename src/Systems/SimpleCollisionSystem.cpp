#include "SimpleCollisionSystem.h"
#include <Components/PositionComponent.h>
#include <Components/SpeedComponent.h>
#include <Components/BoundingBoxComponent.h>

// for std::find
#include <algorithm>


SimpleCollisionSystem::SimpleCollisionSystem(ecs::Manager& aManager)
    : ecs::ISystem_<SimpleCollisionSystem>(aManager) {
    if (ids.empty())
    {
        ids.insert(PositionComponent::sGetID());
        ids.insert(SpeedComponent::sGetID());
        ids.insert(BoundingBoxComponent::sGetID());
    }
}

void SimpleCollisionSystem::Execute(float time_step) const
{
    ecs::Entities found;
    ecs::Entities allEntities = manager.getEntities(this->getComponentIDs());
    for (auto entity1 : allEntities)
    {
        if (std::find(found.begin(), found.end(), entity1) != found.end()){
            continue;
        }
        for (auto entity2 : allEntities)
        {
            if (entity1 == entity2 || std::find(found.begin(), found.end(), entity2) != found.end()){
                continue;
            }
            PositionComponent& pos1 = manager.getComponent<PositionComponent>(entity1);
            BoundingBoxComponent& bbox1 = manager.getComponent<BoundingBoxComponent>(entity1);
            PositionComponent& pos2 = manager.getComponent<PositionComponent>(entity2);
            BoundingBoxComponent& bbox2 = manager.getComponent<BoundingBoxComponent>(entity2);

            float l1 = pos1.x;
            float r1 = l1 + bbox1.width;
            float t1 = pos1.y;
            float b1 = pos1.y + bbox1.height;

            float l2 = pos2.x;
            float r2 = l2 + bbox2.width;
            float t2 = pos2.y;
            float b2 = pos2.y + bbox2.height;

            if (not (l2 < l1 || r2 > r1 || t2 > t1 || b2 < b1)){
                SpeedComponent& speed1 = manager.getComponent<SpeedComponent>(entity1);
                SpeedComponent& speed2 = manager.getComponent<SpeedComponent>(entity2);
                found.push_back(entity1);
                found.push_back(entity2);
                if (l2 > l1 || r2 < r1){
                    speed1.x *= -1;
                    speed2.x *= -1;
                }
                if (t2 < t1 || b2 > b1){
                    speed1.y *= -1;
                    speed2.y *= -1;
                }
            }
        }
    }
}
