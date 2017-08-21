#ifndef SimpleCollisionSystem_HEADER
#define SimpleCollisionSystem_HEADER

#include <SimpleECS/ISystem.h>

class SimpleCollisionSystem : public ecs::ISystem_<SimpleCollisionSystem>
{
    public:
        SimpleCollisionSystem(ecs::Manager& aManager, unsigned int width, unsigned int height);
        void Execute(float time_step) const override;

    private:
        unsigned int mWIDTH;
        unsigned int mHEIGHT;
};

#endif //SimpleCollisionSystem_HEADER
