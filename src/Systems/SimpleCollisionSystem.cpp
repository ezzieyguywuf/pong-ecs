#include "SimpleCollisionSystem.h"
#include <Components/PositionComponent.h>
#include <Components/SpeedComponent.h>
#include <Components/BoundingBoxComponent.h>

// for std::find
#include <set>

SimpleCollisionSystem::SimpleCollisionSystem(ecs::Manager& aManager, unsigned int width, unsigned int height)
    : ecs::ISystem_<SimpleCollisionSystem>(aManager),
      mWIDTH(width),
      mHEIGHT(height){
    if (ids.empty())
    {
        ids.insert(PositionComponent::sGetID());
        ids.insert(BoundingBoxComponent::sGetID());
        ids.insert(SpeedComponent::sGetID());
    }
}

void SimpleCollisionSystem::Execute(float time_step)
{
    std::set<ecs::Entity> found;
    ecs::Entities allEntities = manager.getEntities(this->getComponentIDs());
    for (auto& entity1 : allEntities)
    {
        if (found.find(entity1) != found.end()){
            continue;
        }
        for (auto& entity2 : allEntities)
        {
            if (entity1 == entity2 || found.find(entity2) != found.end()){
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
                found.insert(entity1);
                found.insert(entity2);
                SpeedComponent& speed1 = manager.getComponent<SpeedComponent>(entity1);
                SpeedComponent& speed2 = manager.getComponent<SpeedComponent>(entity2);
                if (l2 > l1 || r2 < r1){
                    speed1.x = 0;
                    speed2.x = 0;
                }
                if (t2 < t1 || b2 > b1){
                    speed1.y = 0;
                    speed2.y = 0;
                }
            }
            if (pos1.x + bbox1.width > mWIDTH - 10)
                pos1.x = mWIDTH - 10 - bbox1.width;
            if (pos1.x < 10)
                pos1.x = 10;
            if (pos1.y + bbox1.height > mHEIGHT - 10)
                pos1.y = mHEIGHT - 10 - bbox1.height;
            if (pos1.y < 10)
                pos1.y = 10;

            if (pos2.x + bbox2.width > mWIDTH - 10)
                pos2.x = mWIDTH - 10 - bbox2.width;
            if (pos2.x < 0)
                pos2.x = 10;
            if (pos2.y + bbox2.height > mHEIGHT - 10)
                pos2.y = mHEIGHT - 10 - bbox2.height;
            if (pos2.y < 0)
                pos2.y = 10;

        }
    }
}
