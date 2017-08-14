#ifndef COMMON_DEFINITIONS_HEADER
#define COMMON_DEFINITIONS_HEADER

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "IComponent.h"

class RenderComponent : public IComponent
{
    public:
        RenderComponent(sf::Drawable* drawable)
            : toDraw(drawable){};

        sf::Drawable* toDraw;
};

class RenderSystem
{
    public:
        RenderSystem(sf::RenderTarget* target)
            : rTarget(target){};
        void Execute(const Entity& anEntity) const;

        sf::RenderTarget* rTarget;
};

void RenderSystem::Execute(const Entity& anEntity) const
{
    const RenderComponent* component = static_cast<const RenderComponent*>(anEntity.components[0]);
    rTarget->clear();
    rTarget->draw(*(component->toDraw));
}

#endif //COMMON_DEFINITIONS_HEADER
