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

class RenderSystem : public ISystem
{
    public:
        RenderSystem(sf::RenderWindow* target)
            : rTarget(target){};
        void Execute() const;

        sf::RenderWindow* rTarget;
};

void RenderSystem::Execute() const
{
    //rTarget->clear();
    //rTarget->draw(*(component->toDraw));
    //rTarget->display();
}

#endif //COMMON_DEFINITIONS_HEADER
