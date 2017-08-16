#include <Systems/RenderSystem.h>
#include <Components/DrawableComponent.h>

// intantiate static vars
ecs::ComponentIDs RenderSystem::ids;

RenderSystem::RenderSystem(sf::RenderWindow* target, ecs::Manager& aManager)
    : rTarget(target),
      ecs::ISystem(aManager) {
    if (ids.empty())
    {
        ids.push_back(DrawableComponent::sGetID());
    }
}

const ecs::ComponentIDs& RenderSystem::getComponentIDs() const{
    return ids;
}

void RenderSystem::Execute() const
{
    rTarget->clear();
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        ecs::IComponent& temp = manager.getComponent(entity, ids[0]);
        DrawableComponent& component = static_cast<DrawableComponent&>(temp);
        rTarget->draw(*(component.toDraw));
    }
    rTarget->display();
}
