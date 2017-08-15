#ifndef ISystem_HEADER
#define ISystem_HEADER

#include "Entity.h"
#include "ComponentTypes.h"
#include "Manager.h"
#include <vector>

namespace ecs{
    class ISystem
    {
        public:
            ISystem(Manager& aManager)
                : manager(aManager){};
            virtual const std::vector<ComponentID>& getComponentIDs() const = 0;
            virtual void Execute() const = 0;

        protected:
            Manager& manager;
    };
};

#endif //ISystem_HEADER
