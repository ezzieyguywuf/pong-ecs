#include "Manager.h"

// for set_intersection
#include <algorithm>
// for back_inserter
#include <iterator>
// for swap
#include <utility>

using ecs::Manager;
using ecs::Entity;

Manager::Manager()
    : nEntities(nullEntity)
{}

Entity Manager::makeEntity(std::unique_ptr<IComponent> component)
{
    Entity id = ++nEntities;
    std::vector<std::unique_ptr<IComponent>> row;
    row.push_back(std::move(component));
    entityMap[id] = std::move(row);
}

Entity Manager::makeEntity(std::vector<std::unique_ptr<IComponent>> components)
{
    Entity id = ++nEntities;
    entityMap[id] = std::move(components);
}

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
