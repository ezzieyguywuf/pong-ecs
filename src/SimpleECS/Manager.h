#ifndef Manager_HEADER
#define Manager_HEADER

#include "Entity.h"
#include "IComponent.h"
#include "Types.h"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>

namespace ecs{
    class Manager
    {
        public:
            Manager();
            ~Manager(){};

            //  make an empty entity
            Entity makeEntity();
            // make an entity with a single component
            Entity makeEntity(ptrIComponent component);
            //Entity makeEntity(std::vector<std::unique_ptr<IComponent>> components);
            // add a component to the given Entity
            void addComponent(const Entity entity, ptrIComponent component);
            //void addComponents(const Entity entity, ptrIComponents component);

            // retrieve all entities that contain a set of components
            Entities getEntities(const ComponentIDs& ids) const;
            // retrieve the component from the entity.
            template<typename T>
            T& getComponent(const Entity entity);
            // check if an entity contains a component
            bool hasComponent(const Entity entity, const ComponentID id) const;

        private:
            // The number of entities being managed. Each new Entity will havue a value of
            // nEntities+1
            Entity nEntities;

            // Each entity has its corresponding list of concrete Components here
            std::map<Entity, std::map<ComponentID, std::unique_ptr<IComponent>>> entityMap;

            // Any component will have a list of associated entities stored here
            //std::map<ComponentID, std::set<Entity>> componentMap;
    };

    template <typename T>
    T& Manager::getComponent(const Entity entity)
    {
        std::map<ComponentID, std::unique_ptr<IComponent>>& comps = entityMap[entity];
        std::unique_ptr<IComponent>& ptr = comps[T::sGetID()];
        T& out = static_cast<T&>(*ptr);
        return out;
        //return static_cast<T&>(*(entityMap[entity][T::sGetID()]));
    }
};

#endif //Manager_HEADER
