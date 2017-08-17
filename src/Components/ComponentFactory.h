#ifndef ComponentFactory_HEADER
#define ComponentFactory_HEADER

#include <SimpleECS/Types.h>

#include <Components/ShapeComponent.h>
#include <Components/PositionComponent.h>
#include <Components/SpeedComponent.h>
#include <Components/BoundingBoxComponent.h>
//#include <Components/FontComponent.h>
//#include <Components/TextComponent.h>
//#include <Components/DisplayTextComponent.h>

#include <SFML/Graphics.hpp>

using ecs::ptrIComponent;

class ComponentFactory
{
    public:
        ptrIComponent makeCircleShape(float rad);
        ptrIComponent makeRectangleShape(float width, float height);
        ptrIComponent makePosition(float x, float y);
        ptrIComponent makeSpeed(float vx, float vy);
        ptrIComponent makeBoundingBox(float width, float height);
};

#endif //ComponentFactory_HEADER
