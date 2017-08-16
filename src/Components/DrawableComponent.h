#ifndef DrawableComponent_Component_HEADER
#define DrawableComponent_Component_HEADER

#include <SimpleECS/IComponent.h>
#include <SFML/Graphics.hpp>

class DrawableComponent : public ecs::Component<DrawableComponent>
{
    public:
        DrawableComponent(sf::Drawable* drawable)
            : toDraw(drawable){};

        sf::Drawable* toDraw;
};

#endif //DrawableComponent_Component_HEADER
