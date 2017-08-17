#ifndef RenderSystem_System_HEADER
#define RenderSystem_System_HEADER

#include <SimpleECS/Manager.h>
#include <SimpleECS/ISystem.h>
#include <SimpleECS/Types.h>

#include <SFML/Graphics.hpp>

class RenderSystem : public ecs::ISystem_<RenderSystem>
{
    public:
        RenderSystem(sf::RenderWindow* target, ecs::Manager& aManager);
        void Execute() const override;

    private:
        sf::RenderWindow* rTarget;
};

#endif //RenderSystem_System_HEADER
