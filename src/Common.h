#ifndef COMMON_DEFINITIONS_HEADER
#define COMMON_DEFINITIONS_HEADER

#include <iostream>

#include "Entity.h"
#include "IComponent.h"

class RenderComponent : public IComponent
{
    public:
        RenderComponent(int val)
            : i(val){};
        int i;
};

class RenderSystem
{
    public:
        void Execute(const Entity& anEntity) const;
};

void RenderSystem::Execute(const Entity& anEntity) const
{
    const RenderComponent* component = static_cast<const RenderComponent*>(anEntity.components[0]);
    std::cout << "val = " << component->i << std::endl;
}

#endif //COMMON_DEFINITIONS_HEADER
