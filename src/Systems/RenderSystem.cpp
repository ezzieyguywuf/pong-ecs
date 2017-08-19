#include <Systems/RenderSystem.h>
#include <Components/RenderableComponent.h>
#include <Components/PositionComponent.h>

RenderSystem::RenderSystem(ecs::Manager& aManager, sf::RenderWindow* target)
    : ecs::ISystem_<RenderSystem>(aManager),
      rTarget(target){

    if (ids.empty())
    {
        ids.insert(RenderableComponent::sGetID());
        ids.insert(PositionComponent::sGetID());
    }
}

void RenderSystem::Execute(float time_step) const
{
    rTarget->clear();
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        RenderableComponent& target = manager.getComponent<RenderableComponent>(entity);
        PositionComponent& pos = manager.getComponent<PositionComponent>(entity);

        if (target.shape){
            target.shape->setPosition(pos.x, pos.y);
            rTarget->draw(*(target.shape));
        }
        else if (target.text){
            target.text->setPosition(pos.x, pos.y);
            rTarget->draw(*(target.text));
        }
    }
    rTarget->display();
}
