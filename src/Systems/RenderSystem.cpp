#include <Systems/RenderSystem.h>
#include <Components/RenderableComponent.h>
#include <Components/PositionComponent.h>

RenderSystem::RenderSystem(sf::RenderWindow* target, ecs::Manager& aManager)
    : rTarget(target),
      ecs::ISystem_<RenderSystem>(aManager) {
    if (ids.empty())
    {
        ids.insert(RenderableComponent::sGetID());
        ids.insert(PositionComponent::sGetID());
    }
}

void RenderSystem::Execute() const
{
    rTarget->clear();
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        RenderableComponent& target = manager.getComponent<RenderableComponent>(entity);
        PositionComponent& pos = manager.getComponent<PositionComponent>(entity);

        target.transformable.setPosition(pos.x, pos.y);
        rTarget->draw(target.drawable);
    }
    rTarget->display();
}
