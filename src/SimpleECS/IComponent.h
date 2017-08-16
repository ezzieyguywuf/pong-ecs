#ifndef IComponent_HEADER
#define IComponent_HEADER

#include <SimpleECS/Types.h>

namespace ecs{
    // ----- Declarations -----

    class IComponent{
        public:
            virtual const ComponentID getID() const = 0;
    };

    template <class T>
    class Component : public IComponent{
        public:
            static std::type_index sGetID()//;
            {
                return std::type_index(typeid(T));
            }
            const std::type_index getID() const override//;
            {
                return std::type_index(typeid(T));
            }
    };

    // ----- Definitions -----
    
    //template <class T>
    //inline std::type_index Component<T>::getID() const
    //{
        //return std::type_index(typeid(T));
    //}

    //template <class T>
    //inline const std::type_index sGetID()
    //{
        //return std::type_index(typeid(T));
    //}
};

#endif //IComponent_HEADER
