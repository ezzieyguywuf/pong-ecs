#include <Systems/RenderSFML.h>
#include <Components/RenderSFML.h>

using sys::RenderSFML;

RenderSFML::RenderSFML(sf::RenderWindow* target, ecs::Manager& aManager)
    : rTarget(target),
      ecs::ISystem(aManager) {
    if (ids.empty())
    {
        ids.push_back(comp::RenderSFML::sGetID());
    }
}

const ecs::ComponentIDs& RenderSFML::getComponentIDs() const{
    return ids;
}

void RenderSFML::Execute() const
{
    rTarget->clear();
    for (auto entity : manager.getEntities(this->getComponentIDs()))
    {
        ecs::IComponent& temp = manager.getComponent(entity, ids[0]);
        comp::RenderSFML& comp = static_cast<comp::RenderSFML&>(temp);
        rTarget->draw(*(comp.toDraw));
    }
    rTarget->display();
}
