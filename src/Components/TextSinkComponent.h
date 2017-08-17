#ifndef TextSinkComponent_HEADER
#define TextSinkComponent_HEADER

#include <SimpleECS/Types.h>

#include <SimpleECS/IComponent.h>
#include <string>
#include <SFML/Graphics.hpp>

class TextSinkComponent : public ecs::IComponent_<TextSinkComponent>
{
    public:
        TextSinkComponent(std::string filename) {
            font.loadFromFile(filename);
            text.setFont(font);
            text.setCharacterSize(8);
            text.setFillColor(sf::Color::Blue);}

        sf::Text text;
        sf::Font font;
};

#endif //TextSinkComponent_HEADER
