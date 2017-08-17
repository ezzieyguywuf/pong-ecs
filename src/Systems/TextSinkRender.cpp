#include <Systems/TextSinkRenderSystem.h>
#include <Components/TextComponent.h>
#include <Components/ShapeComponent.h>

#include <sstream>

TextSinkRenderSystem::TextSinkRenderSystem(sf::RenderWindow* target, ecs::Manager& aManager)
    : rTarget(target),
      ecs::ISystem_<RenderSystem>(aManager) {
    if (ids.empty())
    {
        ids.insert(TextComponent::sGetID());
        ids.insert(TextSinkComponent::sGetID());
    }
}

void TextSinkRenderSystem::Execute() const
{
    rTarget->clear();
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        TextComponent& sink = manager.getComponent<TextComponent>(entity);
        TextSinkComponent& source = manager.getComponent<TextSinkComponent>(entity);

        std::stream out;
        out << "pos| x = " << source.

        sink.text.setString(outString);
        rTarget->draw(*(target.shape));
    }
    rTarget->display();
}
