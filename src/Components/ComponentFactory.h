#ifndef ComponentFactory_HEADER
#define ComponentFactory_HEADER

#include <SimpleECS/Types.h>

#include <Components/RenderWindowComponent.h>
#include <Components/RenderableComponent.h>
#include <Components/PositionComponent.h>
#include <Components/SpeedComponent.h>
#include <Components/BoundingBoxComponent.h>
#include <Components/TextSinkComponent.h>
#include <Components/TextSourceComponent.h>

#include <SFML/Graphics.hpp>

#include <string>

using ecs::ptrIComponent;

class ComponentFactory
{
    public:
        ptrIComponent makeRenderWindow(sf::RenderWindow& window);
        ptrIComponent makeTextShape(sf::Font& font);
        ptrIComponent makeCircleShape(float rad);
        ptrIComponent makeRectangleShape(float width, float height);
        ptrIComponent makePosition(float x, float y);
        ptrIComponent makeSpeed(float vx, float vy);
        ptrIComponent makeBoundingBox(float width, float height);
        ptrIComponent makeTextSink(ecs::Entity entity);
        ptrIComponent makeTextSource(ecs::Entity entity);
};

#endif //ComponentFactory_HEADER
