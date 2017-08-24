#ifndef TextSinkRenderSystem_HEADER
#define TextSinkRenderSystem_HEADER

#include <SimpleECS/Types.h>
#include <SimpleECS/Manager.h>
#include <SimpleECS/ISystem.h>

#include <SFML/Graphics.hpp>

class TextSinkRenderSystem : public ecs::ISystem_<TextSinkRenderSystem>
{
    public:
        TextSinkRenderSystem(ecs::Manager& aManager);
        void Execute(float time_step) override;
};

#endif //TextSinkRenderSystem_HEADER
