#include <Systems/TextSinkRenderSystem.h>
#include <Components/TextSinkComponent.h>
#include <Components/TextSourceComponent.h>
#include <Components/RenderableComponent.h>
#include <Components/SpeedComponent.h>

#include <sstream>
#include <cmath>

TextSinkRenderSystem::TextSinkRenderSystem(ecs::Manager& aManager)
        : ecs::ISystem_<TextSinkRenderSystem>(aManager){
    if (ids.empty())
    {
        ids.insert(TextSourceComponent::sGetID());
        ids.insert(TextSinkComponent::sGetID());
    }
}

void TextSinkRenderSystem::Execute(float time_step)
{
    for (auto& entity : manager.getEntities(this->getComponentIDs()))
    {
        TextSourceComponent& source = manager.getComponent<TextSourceComponent>(entity);
        TextSinkComponent& sink = manager.getComponent<TextSinkComponent>(entity);

        RenderableComponent& shape = manager.getComponent<RenderableComponent>(source.entity);
        RenderableComponent& text  = manager.getComponent<RenderableComponent>(sink.entity);

        std::stringstream out;
        out << "pos| x = " << std::round(shape.shape->getPosition().x);
        out << ", y = " << std::round(shape.shape->getPosition().y);
        if (manager.hasComponent(source.entity, SpeedComponent::sGetID()))
        {
            auto& speed = manager.getComponent<SpeedComponent>(source.entity);
            out << ", spd| x = " << speed.x;
            out << ", y = " << speed.y;
        }

        text.text->setString(out.str());
    }
}
