#ifndef COMMON_DEFINITIONS_HEADER
#define COMMON_DEFINITIONS_HEADER

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class IComponent{
    public:
        virtual ~IComponent() = 0;
};

class RenderComponent : public IComponent
{
    public:
        RenderComponent(int val)
            : i(val){};
        int i;
};

class Entity{
    public:
        Entity(std::string aName)
            : name(aName){};

        std::vector<IComponent*> components;

    private:
        std::string name;
};

class RenderSystem
{
    public:
        void Execute(const Entity& anEntity) const;
};


IComponent::~IComponent(){}

void RenderSystem::Execute(const Entity& anEntity) const
{
    const RenderComponent* component = static_cast<const RenderComponent*>(anEntity.components[0]);
    std::cout << "val = " << component->i << std::endl;
}

#endif //COMMON_DEFINITIONS_HEADER
