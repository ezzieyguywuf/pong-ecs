#ifndef RenderableComponent_Component_HEADER
#define RenderableComponent_Component_HEADER

#include <SimpleECS/IComponent.h>
#include <SFML/Graphics.hpp>
#include <memory>

class RenderableComponent : public ecs::IComponent_<RenderableComponent>
{
    public:
        RenderableComponent(std::unique_ptr<sf::Shape> aShape)
            : shape(std::move(aShape)){};
        RenderableComponent(sf::Font& aFont)
            : text(new sf::Text()){
                text->setFont(aFont);
                text->setCharacterSize(10);
            }

        std::unique_ptr<sf::Shape> shape;
        std::unique_ptr<sf::Text> text;
};

#endif //RenderableComponent_Component_HEADER
