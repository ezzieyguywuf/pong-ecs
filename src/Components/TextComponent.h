#ifndef TextComponent_HEADER
#define TextComponent_HEADER

#include <SimpleECS/IComponent.h>
#include <string>
#include <SFML/Graphics.hpp>

class TextComponent : public ecs::IComponent_<TextComponent>
{
    public:
        TextComponent(std::string aText)
            : text.setString(aText){};

        bool sf::Text text;
};

#endif //TextComponent_HEADER
