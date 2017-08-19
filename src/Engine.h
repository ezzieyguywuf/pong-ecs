#ifndef Engine_HEADER
#define Engine_HEADER

#include <SimpleECS/ISystem.h>
#include <SimpleECS/Manager.h>
#include <SimpleECS/Types.h>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

enum class When{
    Before,
    During,
    After
};


class Engine
{
    public:
        // TICK_RATE should be provided in units of ticks per second
        Engine(sf::RenderWindow& aWindow, unsigned int rate=30);
        ~Engine();

        // The different values of `when` mean:
        //  Before -> runs at TICK_RATE ticks per second
        //  During -> runs as fast as possible, before the when=0 systems
        //  After  -> runs as fast as possible, after the when=0 systems
        void addSystem(ecs::ptrISystem aSystem, const When when=When::During);
        void start();
        const std::set<sf::Keyboard::Key>& getEventsRef() const;

    private:
        void processSystems(const ecs::ptrISystems& systems);
        void Input();
        void Update();
        void Draw();

        sf::Event event;
        std::set<sf::Keyboard::Key> events;
        sf::RenderWindow& myWindow;
        unsigned int TICK_RATE;
        float TIME_STEP;
        ecs::ptrISystems systemsDuring;
        ecs::ptrISystems systemsBefore;
        ecs::ptrISystems systemsAfter;

};

#endif //Engine_HEADER
