#include <Systems/TextSinkRenderSystem.h>
#include <Components/TextSinkComponent.h>
#include <Components/TextSourceComponent.h>
#include <Components/RenderableComponent.h>

#include <sstream>

TextSinkRenderSystem::TextSinkRenderSystem(ecs::Manager& aManager)
        : ecs::ISystem_<TextSinkRenderSystem>(aManager){
    if (ids.empty())
    {
        ids.insert(TextSourceComponent::sGetID());
        ids.insert(TextSinkComponent::sGetID());
    }
}

void TextSinkRenderSystem::Execute() const
{
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        TextSourceComponent& source = manager.getComponent<TextSourceComponent>(entity);
        TextSinkComponent& sink = manager.getComponent<TextSinkComponent>(entity);

        RenderableComponent& shape = manager.getComponent<RenderableComponent>(source.entity);
        RenderableComponent& text  = manager.getComponent<RenderableComponent>(sink.entity);

        std::stringstream out;
        out << "pos| x = " << shape.shape->getPosition().x;
        out << ", y = " << shape.shape->getPosition().y;

        text.text->setString(out.str());
    }
}
