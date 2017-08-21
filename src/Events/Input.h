#ifndef Input_HEADER
#define Input_HEADER

#include "Event.h"
#include <SFML/Window.hpp>

namespace Event{
    class Input : public IEvent
    {
        public:
            Input(sf::Keyboard::Key aKey, bool isPressed=true)
                : key(aKey),
                  pressed(isPressed){};
            sf::Keyboard::Key key;
            bool pressed;
    };
}

#endif //Input_HEADER
