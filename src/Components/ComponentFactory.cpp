#include "ComponentFactory.h"
#include <memory>

using ecs::ptrIComponent;

ptrIComponent ComponentFactory::makeCircleShape(float rad)
{
    std::unique_ptr<sf::Shape> shape(new sf::CircleShape(rad));
    return ptrIComponent(new ShapeComponent(std::move(shape)));
}

ptrIComponent ComponentFactory::makeRectangleShape(float width, float height)
{
    sf::Vector2f size(width, height);
    std::unique_ptr<sf::Shape> shape(new sf::RectangleShape(size));
    return ptrIComponent(new ShapeComponent(std::move(shape)));
}

ptrIComponent ComponentFactory::makePosition(float x, float y)
{
    return ptrIComponent(new PositionComponent(x, y));
}

ptrIComponent ComponentFactory::makeSpeed(float vx, float vy)
{
    return ptrIComponent(new SpeedComponent(vx, vy));
}

ptrIComponent ComponentFactory::makeBoundingBox(float width, float height)
{
    return ptrIComponent(new BoundingBoxComponent(width, height));
}
