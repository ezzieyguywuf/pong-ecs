#ifndef InputHandlerSystem_HEADER
#define InputHandlerSystem_HEADER

#include <SimpleECS/Types.h>
#include <SimpleECS/Manager.h>
#include <SimpleECS/ISystem.h>

#include <Events/IEvent.h>
#include <Events/EventManager.h>

#include <SFML/Window.hpp>

using EventMap = std::map<sf::Keyboard::Key, bool>;

class InputHandlerSystem : public ecs::ISystem_<InputHandlerSystem>
{
    public:
        InputHandlerSystem(ecs::Manager& aManager, Event::EventManager& anEventManager);
        void processEvent(const Event::IEvent& anEvent);
        void Execute(float time_step) const override;

    private:
        EventMap eventMap;
        Event::EventManager& eventManager;
};

#endif //InputHandlerSystem_HEADER
