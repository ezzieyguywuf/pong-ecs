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
        ecs::IComponent& temp1 = manager.getComponent(entity, ShapeComponent::sGetID());
        ShapeComponent& target = static_cast<ShapeComponent&>(temp1);

        ecs::IComponent& temp2 = manager.getComponent(entity, PositionComponent::sGetID());
        PositionComponent& pos = static_cast<PositionComponent&>(temp2);

        target.shape->setPosition(pos.x, pos.y);
        rTarget->draw(*(target.shape));
    }
    rTarget->display();
}
