#ifndef IComponent_HEADER
#define IComponent_HEADER

#include "ComponentTypes.h"

namespace ecs{
    class IComponent{
        public:
            static ComponentID nextID();
            virtual ComponentID getID() = 0;
    };

    template <class T>
    class Component : public IComponent{
        public:
            static ComponentID sGetID(){
                return sID;
            }
            ComponentID getID(){
                return sID;
            }
        private:
            static ComponentID sID;
    };

    
    inline ComponentID IComponent::nextID() {
        static ComponentID sNextID = 0;
        return sNextID++;
    }

    template <class T>
    ComponentID Component<T>::sID = IComponent::nextID();
}

#endif //IComponent_HEADER
