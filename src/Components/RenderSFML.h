#ifndef ComponentRenderSFML_HEADER
#define ComponentRenderSFML_HEADER

#include <SimpleECS/IComponent.h>
#include <SFML/Graphics.hpp>

namespace comp{
    class RenderSFML : public ecs::Component<RenderSFML>
    {
        public:
            RenderSFML(sf::Drawable* drawable)
                : toDraw(drawable){};

            sf::Drawable* toDraw;
    };
}

#endif //ComponentRenderSFML_HEADER
