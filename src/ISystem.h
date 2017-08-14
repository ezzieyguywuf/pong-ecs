#ifndef ISystem_HEADER
#define ISystem_HEADER

#include "Entity.h"
#include <memory>

class ISystem
{
    public:
        ~ISystem(){};

        virtual void Execute(const Entity& entity) const = 0;

};

#endif //ISystem_HEADER
