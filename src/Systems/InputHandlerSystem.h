#ifndef InputHandlerSystem_HEADER
#define InputHandlerSystem_HEADER

#include <SimpleECS/Types.h>
#include <SimpleECS/Manager.h>
#include <SimpleECS/ISystem.h>

#include <SFML/Window.hpp>

using Events = std::set<sf::Keyboard::Key>;

class InputHandlerSystem : public ecs::ISystem_<InputHandlerSystem>
{
    public:
        InputHandlerSystem(ecs::Manager& aManager, const Events& aEvents);
        void Execute(float time_step) const override;

    private:
        const Events& events;
};

#endif //InputHandlerSystem_HEADER
