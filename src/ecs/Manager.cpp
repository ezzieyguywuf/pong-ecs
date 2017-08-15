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

Entity Manager::makeEntity(std::unique_ptr<IComponent> component)
{
    Entity entity = ++nEntities;
    this->addComponent(entity, std::move(component));
    return entity;
}

//Entity Manager::makeEntity(std::vector<std::unique_ptr<IComponent>> components)
//{
    //Entity entity = ++nEntities;
    //this->addComponents(entity, std::move(components));
    //return entity;
//}

void Manager::addComponent(const Entity entity, std::unique_ptr<IComponent> component)
{
    std::map<ComponentID, std::unique_ptr<IComponent>> inner;
    inner.insert(std::make_pair(component->getID(), std::move(component)));
    entityMap.insert(std::make_pair(entity, std::move(inner)));
}

//void Manager::addComponents(const Entity entity, std::vector<std::unique_ptr<IComponent>> components)
//{
    //for (auto component : components)
    //{
        //this->addComponent(entity, std::move(component));
    //}
//}

std::vector<Entity> Manager::getEntities(const std::vector<ComponentID>& ids) const
{
    std::vector<Entity> result;
    std::vector<Entity> buffer;
    for (auto id : ids){
        buffer.clear();
        std::set<Entity> check = componentTable.at(id);

        std::set_intersection(result.begin(), result.end(),
                              check.begin(), check.end(),
                              std::back_inserter(buffer));
        std::swap(result, buffer);
    }
    return result;
}

IComponent& Manager::getComponent(const Entity entity, const ComponentID cID)
{
    return *(entityMap[entity][cID]);
}
