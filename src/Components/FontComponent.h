#ifndef FontComponent_HEADER
#define FontComponent_HEADER

#include <SimpleECS/IComponent.h>
#include <string>
#include <SFML/Graphics.hpp>

class FontComponent : public ecs::IComponent_<FontComponent>
{
    public:
        FontComponent(std::string filename){
            font.loadFromFile(filename);
        };

        sf::Font font;
};

#endif //FontComponent_HEADER
