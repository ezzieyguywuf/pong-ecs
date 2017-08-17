#ifndef ShapeComponent_HEADER
#define ShapeComponent_HEADER

#include <SimpleECS/IComponent.h>
#include <SFML/Graphics.hpp>

class ShapeComponent : public ecs::IComponent_<ShapeComponent>
{
    public:
        ShapeComponent(sf::Shape& aShape)
            : shape(aShape){};

        sf::Shape& shape;
};

#endif //ShapeComponent_HEADER
