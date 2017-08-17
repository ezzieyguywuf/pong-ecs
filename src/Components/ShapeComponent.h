#ifndef ShapeComponent_HEADER
#define ShapeComponent_HEADER

#include <SimpleECS/IComponent.h>
#include <SFML/Graphics.hpp>
#include <memory>

class ShapeComponent : public ecs::IComponent_<ShapeComponent>
{
    public:
        ShapeComponent(std::unique_ptr<sf::Shape> aShape)
            : shape(std::move(aShape)){};

        std::unique_ptr<sf::Shape> shape;
};

#endif //ShapeComponent_HEADER
