#include "Engine.h"
#include "Common.h"
#include "Display.h"
#include "SFML/Graphics.hpp"
#include "ecs/ISystem.h"
#include "ecs/IComponent.h"
#include "ecs/Manager.h"
#include <memory>

std::vector<ecs::ComponentID> RenderSystem::ids(RenderComponent::sGetID());

int main(int argc, char ** argv) {
    ecs::Manager manager;

    sf::CircleShape ballShape(5);
    RenderComponent* rComp = new  RenderComponent(&ballShape);

    manager.makeEntity(std::move(std::unique_ptr<ecs::IComponent>(rComp)));

    sf::RenderWindow rWindow(sf::VideoMode(640, 480), "SFML Pong Demo");
    Display display(rWindow);

    ecs::ISystem* renderer = new RenderSystem(&rWindow, manager);

    Engine engine(display);
    engine.start();

    delete rComp;
    return 0;
}
