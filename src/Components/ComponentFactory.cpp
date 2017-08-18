#include "ComponentFactory.h"
#include <memory>

using ecs::ptrIComponent;

ptrIComponent ComponentFactory::makeRenderWindow(sf::RenderWindow& window)
{
    return ptrIComponent(new RenderWindowComponent(window));
}

ptrIComponent ComponentFactory::makeCircleShape(float rad)
{
    std::unique_ptr<sf::Shape> shape(new sf::CircleShape(rad));
    shape->setFillColor(sf::Color::Blue);
    return ptrIComponent(new RenderableComponent(std::move(shape)));
}

ptrIComponent ComponentFactory::makeRectangleShape(float width, float height)
{
    sf::Vector2f size(width, height);
    std::unique_ptr<sf::Shape> shape(new sf::RectangleShape(size));
    return ptrIComponent(new RenderableComponent(std::move(shape)));
}

ptrIComponent ComponentFactory::makeTextShape(sf::Font& font)
{
    return ptrIComponent(new RenderableComponent(font));
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

ptrIComponent ComponentFactory::makeTextSink(ecs::Entity entity)
{
    return ptrIComponent(new TextSinkComponent(entity));
}

ptrIComponent ComponentFactory::makeTextSource(ecs::Entity entity)
{
    return ptrIComponent(new TextSourceComponent(entity));
}
