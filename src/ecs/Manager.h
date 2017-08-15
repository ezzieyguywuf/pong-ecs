#ifndef Manager_HEADER
#define Manager_HEADER

#include "ecs/Entity.h"
#include "ecs/IComponent.h"
#include "ComponentTypes.h"
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

            Entity makeEntity(std::unique_ptr<IComponent> component);
            Entity makeEntity(std::vector<std::unique_ptr<IComponent>> components);
            std::vector<Entity> getEntities(const std::vector<ComponentID>& ids) const;

        private:
            // The number of entities being managed. Each new Entity will havue a value of
            // nEntities+1
            Entity nEntities;

            // Each entity has its corresponding list of concrete Components here
            std::map<Entity, std::vector<std::unique_ptr<IComponent>>> entityMap;

            // Any component will have a list of associated entities stored here
            std::map<ComponentID, std::set<Entity>> componentTable;
    };
};

#endif //Manager_HEADER
