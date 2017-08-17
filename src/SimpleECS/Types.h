#ifndef ECS_Types_HEADER
#define ECS_Types_HEADER

#include <vector>
#include <set>
#include <memory>
#include <typeindex>

using std::vector;
using std::set;
using std::unique_ptr;

namespace ecs{
    class IComponent;
    class ISystem;

    // ComponentIDs is defined in IComponent.h
    typedef std::type_index ComponentID;
    typedef set<ComponentID> ComponentIDs;

    // We'll handle interfaces as unique_ptr
    typedef unique_ptr<IComponent> ptrIComponent;
    typedef unique_ptr<ISystem> ptrISystem;
    typedef vector<ptrIComponent> ptrIComponents;
    typedef vector<ptrISystem> ptrISystems;

    // an Entity is just an integer.
    typedef unsigned int Entity;
    static const Entity nullEntity = 0;
    typedef vector<Entity> Entities;
}

#endif //ECS_Types_HEADER
