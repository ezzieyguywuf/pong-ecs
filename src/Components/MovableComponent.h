#ifndef MovableComponent_HEADER
#define MovableComponent_HEADER

#include <SimpleECS/IComponent.h>
#include <SFML/Window.hpp>

using Key = sf::Keyboard::Key;

class MovableComponent : public ecs::IComponent_<MovableComponent>
{
    public:
        MovableComponent(
            Key kup=Key::Unknown, 
            Key kdown=Key::Unknown, 
            Key kleft=Key::Unknown, 
            Key kright=Key::Unknown)
                : up(kup),
                  down(kdown),
                  left(kleft),
                  right(kright){};

        Key up;
        Key down;
        Key left;
        Key right;
};

#endif //MovableComponent_HEADER

