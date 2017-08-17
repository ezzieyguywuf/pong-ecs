#ifndef RenderableComponent_Component_HEADER
#define RenderableComponent_Component_HEADER

#include <SimpleECS/IComponent.h>
#include <SFML/Graphics.hpp>
#include <memory>

class RenderableComponent : public ecs::IComponent_<RenderableComponent>
{
    public:
        RenderableComponent(std::unique_ptr<sf::Shape> aShape)
            : shape(std::move(aShape)),
              drawable(*shape),
              transformable(*shape){};
        RenderableComponent(std::unique_ptr<sf::Text> aText)
            : text(std::move(aText)),
              drawable(*text),
              transformable(*text){};

        sf::Drawable& drawable;
        sf::Transformable& transformable;
    private:
        std::unique_ptr<sf::Shape> shape;
        std::unique_ptr<sf::Text> text;
};

#endif //RenderableComponent_Component_HEADER
