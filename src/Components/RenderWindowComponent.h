#ifndef RenderWindowComponent_Component_HEADER
#define RenderWindowComponent_Component_HEADER

#include <SimpleECS/IComponent.h>
#include <SFML/Graphics.hpp>

class RenderWindowComponent : public ecs::IComponent_<RenderWindowComponent>
{
    public:
        RenderWindowComponent(sf::RenderWindow& aWindow)
            : window(aWindow){};

        sf::RenderWindow& window;
};

#endif //RenderWindowComponent_Component_HEADER
