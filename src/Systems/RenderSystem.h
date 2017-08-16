#ifndef RenderSystem_System_HEADER
#define RenderSystem_System_HEADER

#include <SimpleECS/Manager.h>
#include <SimpleECS/ISystem.h>
#include <SimpleECS/Types.h>

#include <SFML/Graphics.hpp>

class RenderSystem : public ecs::ISystem
    {
        public:
            RenderSystem(sf::RenderWindow* target, ecs::Manager& aManager);
            const ecs::ComponentIDs& getComponentIDs() const;
            void Execute() const override;

            sf::RenderWindow* rTarget;
        private:
            static ecs::ComponentIDs ids;
    };

#endif //RenderSystem_System_HEADER
