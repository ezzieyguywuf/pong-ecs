#ifndef Engine_HEADER
#define Engine_HEADER

#include "ecs/Entity.h"
//#include "ISystem.h"
//#include "IComponent.h"
#include "Display.h"

class Engine
{
    public:
        Engine(Display& aDisp)
            : myDisplay(aDisp){};
        ~Engine(){};

        void start();

    private:
        void Input();
        void Update();
        void Draw();

        Display myDisplay;
};

#endif //Engine_HEADER
