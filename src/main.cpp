// current dir
#include <Engine.h>
#include <Display.h>
#include <Components/DrawableComponent.h>
#include <Systems/RenderSystem.h>

// local lib
#include <SimpleECS/ISystem.h>
#include <SimpleECS/IComponent.h>
#include <SimpleECS/Manager.h>

// semi-local lib
#include <SFML/Graphics.hpp>

// system lib
#include <memory>
#include <iostream>

// intantiate static vars
ecs::ComponentIDs RenderSystem::ids;

int main(int argc, char ** argv) {
    ecs::Manager manager;

    sf::CircleShape ballShape(15);
    ecs::ptrIComponent cPtr(new DrawableComponent(&ballShape));
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
