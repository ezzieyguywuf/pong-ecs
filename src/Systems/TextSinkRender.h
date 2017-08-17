#ifndef TextSinkRenderSystem_HEADER
#define TextSinkRenderSystem_HEADER

#include <SimpleECS/Types.h>
#include <SimpleECS/Manager.h>
#include <SimpleECS/ISystem.h>

#include <SFML/Graphics.hpp>

class TextSinkRenderSystem : public ecs::ISystem_<TextSinkRenderSystem>
{
    public:
        TextSinkRenderSystem(sf::RenderWindow* target, ecs::Manager& aManager);
        void Execute() const override;

    private:
        sf::RenderWindow* rTarget;
};

#endif //TextSinkRenderSystem_HEADER
