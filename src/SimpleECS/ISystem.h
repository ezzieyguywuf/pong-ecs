#ifndef ISystem_HEADER
#define ISystem_HEADER

#include "Entity.h"
#include "IComponent.h"
#include <SimpleECS/Manager.h>
#include <vector>


namespace ecs{
    class ISystem
    {
        public:
            virtual const ecs::ComponentIDs& getComponentIDs() const = 0;
            virtual void Execute(float time_step) = 0;
    };

    template <class T>
    class ISystem_ : public ISystem
    {
        public:
            ISystem_(Manager& aManager)
                : manager(aManager){};
            const ecs::ComponentIDs& getComponentIDs() const
            {
                return ids;
            }
        protected:
            static ecs::ComponentIDs ids;
            Manager& manager;
    };

     //intantiate static vars
    template <class T>
    ecs::ComponentIDs ecs::ISystem_<T>::ids;
}

#endif //ISystem_HEADER
