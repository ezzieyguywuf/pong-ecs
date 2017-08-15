#include "Engine.h"
#include "Common.h"
#include "Display.h"
#include "SFML/Graphics.hpp"
#include "ecs/ISystem.h"
#include "ecs/IComponent.h"
#include "ecs/Manager.h"
#include <memory>

ecs::ComponentIDs RenderSystem::ids;
int main(int argc, char ** argv) {
    ecs::Manager manager;

    sf::CircleShape ballShape(15);
    ecs::ptrIComponent cPtr(new RenderComponent(&ballShape));
    std::cout << "cPtr->getID() = " << cPtr->getID() << std::endl;
    manager.makeEntity(std::move(cPtr));

    sf::RenderWindow rWindow(sf::VideoMode(640, 480), "SFML Pong Demo");
    Display display(rWindow);

    ecs::ISystem* renderer = new RenderSystem(&rWindow, manager);
    std::cout << "renderer->getComponentIDs() = " << renderer->getComponentIDs()[0] << std::endl;
    ecs::ptrISystem rPtr(renderer);

    Engine engine(display);
    engine.addSystem(std::move(rPtr), When::After);
    engine.start();

    delete renderer;
    return 0;
}
