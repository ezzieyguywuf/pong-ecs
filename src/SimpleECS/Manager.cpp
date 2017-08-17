#include "Manager.h"

// for set_intersection
#include <algorithm>
// for back_inserter
#include <iterator>
// for swap and make_pair
#include <utility>

using ecs::Manager;
using ecs::Entity;
using ecs::IComponent;

Manager::Manager()
    : nEntities(nullEntity)
{}

Entity Manager::makeEntity()
{
    return ++nEntities;
}

Entity Manager::makeEntity(ptrIComponent component)
{
    Entity entity = this->makeEntity();
    this->addComponent(entity, std::move(component));
    return entity;
}

//Entity Manager::makeEntity(std::vector<std::unique_ptr<IComponent>> components)
//{
    //Entity entity = ++nEntities;
    //this->addComponents(entity, std::move(components));
    //return entity;
//}

void Manager::addComponent(const Entity entity, ptrIComponent component)
{
    //componentMap[component->getID()].insert(entity);

    entityMap[entity][component->getID()] = std::move(component);
}

bool Manager::hasComponent(const Entity entity, const ComponentID id) const
{
    auto& mapItem = entityMap.at(entity);
    if (mapItem.find(id) != mapItem.end()){
        return true;
    }
    return false;
}

//void Manager::addComponents(const Entity entity, std::vector<std::unique_ptr<IComponent>> components)
//{
    //for (auto component : components)
    //{
        //this->addComponent(entity, std::move(component));
    //}
//}

ecs::Entities Manager::getEntities(const ComponentIDs& ids) const
{
    Entities result;
    for (auto& EntityData : entityMap){
        ecs::ComponentIDs check;
        for (auto& ComponentData : EntityData.second)
        {
            check.insert(ComponentData.first);
        }
        if (std::includes(
                    check.begin(), check.end(),
                    ids.begin(), ids.end()))
        {
            result.push_back(EntityData.first);
        }
    }
    return result;
}

