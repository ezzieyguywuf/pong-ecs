#ifndef SystemRenderSFML_HEADER
#define SystemRenderSFML_HEADER

#include <SimpleECS/Manager.h>
#include <SimpleECS/ISystem.h>
#include <SimpleECS/Types.h>

#include <SFML/Graphics.hpp>

namespace sys{
    class RenderSFML : public ecs::ISystem
        {
            public:
                RenderSFML(sf::RenderWindow* target, ecs::Manager& aManager);
                const ecs::ComponentIDs& getComponentIDs() const;
                void Execute() const override;

                sf::RenderWindow* rTarget;
            private:
                static ecs::ComponentIDs ids;
        };
};

#endif //SystemRenderSFML_HEADER
