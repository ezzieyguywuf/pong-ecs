#ifndef COMMON_DEFINITIONS_HEADER
#define COMMON_DEFINITIONS_HEADER

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ecs/Entity.h"
#include "ecs/IComponent.h"
#include "ecs/ISystem.h"

class RenderComponent : public ecs::Component<RenderComponent>
{
    public:
        RenderComponent(sf::Drawable* drawable)
            : toDraw(drawable){};

        sf::Drawable* toDraw;
};

class RenderSystem : public ecs::ISystem
{
    public:
        RenderSystem(sf::RenderWindow* target, ecs::Manager& aManager)
            : rTarget(target),
              ISystem(aManager){};
        const std::vector<ComponentID>& getComponentIDs() const{
            return ids;
        }
        void Execute() const override;

        sf::RenderWindow* rTarget;
    private:
        static std::vector<ComponentID> ids;
};


void RenderSystem::Execute() const
{
    rTarget->clear();
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        ecs::IComponent& temp = manager.getComponent(entity, ids[0]);
        RenderComponent& comp = static_cast<RenderComponent&>(temp);
        rTarget->draw(*(comp.toDraw));
    }
    rTarget->display();
}

#endif //COMMON_DEFINITIONS_HEADER
