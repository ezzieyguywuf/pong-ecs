#ifndef Engine_HEADER
#define Engine_HEADER

#include "ecs/ISystem.h"
#include "ecs/Manager.h"
#include "Display.h"
#include <vector>
#include <memory>

enum class When{
    Before,
    During,
    After
};

class Engine
{
    public:
        // TICK_RATE should be provided in units of ticks per second
        Engine(Display& aDisp, unsigned int rate=30);
        ~Engine();

        // The different values of `when` mean:
        //  Before -> runs at TICK_RATE ticks per second
        //  During -> runs as fast as possible, before the when=0 systems
        //  After  -> runs as fast as possible, after the when=0 systems
        void addSystem(std::unique_ptr<ecs::ISystem> aSystem, const When when=When::During);
        void start();

    private:
        void processSystems(const std::vector<std::unique_ptr<ecs::ISystem>>& systems);
        void Input();
        void Update();
        void Draw();

        Display myDisplay;
        unsigned int TICK_RATE;
        std::vector<std::unique_ptr<ecs::ISystem>> systemsDuring;
        std::vector<std::unique_ptr<ecs::ISystem>> systemsBefore;
        std::vector<std::unique_ptr<ecs::ISystem>> systemsAfter;

};

#endif //Engine_HEADER
