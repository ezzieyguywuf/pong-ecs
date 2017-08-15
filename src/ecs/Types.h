#ifndef ECS_Types_HEADER
#define ECS_Types_HEADER

#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

namespace ecs{
    class IComponent;
    class ISystem;

    // ComponentIDs is defined in IComponent.h
    typedef vector<ComponentID> ComponentIDs;

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
