#include <Systems/RenderSystem.h>
#include <Components/ShapeComponent.h>
#include <Components/PositionComponent.h>

RenderSystem::RenderSystem(sf::RenderWindow* target, ecs::Manager& aManager)
    : rTarget(target),
      ecs::ISystem_<RenderSystem>(aManager) {
    if (ids.empty())
    {
        ids.insert(ShapeComponent::sGetID());
        ids.insert(PositionComponent::sGetID());
    }
}

void RenderSystem::Execute() const
{
    rTarget->clear();
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        ShapeComponent& target = manager.getComponent<ShapeComponent>(entity);
        PositionComponent& pos = manager.getComponent<PositionComponent>(entity);

        target.shape->setPosition(pos.x, pos.y);
        rTarget->draw(*(target.shape));
    }
    rTarget->display();
}
