// current dir
#include <Engine.h>
#include <Display.h>

#include <Components/ComponentFactory.h>

#include <Systems/RenderSystem.h>
#include <Systems/PhysicsSystem.h>
#include <Systems/SimpleCollisionSystem.h>

// local lib
#include <SimpleECS/ISystem.h>
#include <SimpleECS/IComponent.h>
#include <SimpleECS/Manager.h>

// semi-local lib

// system lib
#include <memory>
#include <iostream>

void createEntities(Manager& manager)
{
    ComponentFactory factory;
    // Make our entities and add the appropriate components.
    // NOTE: this could be pulled, theoretically, from some sort of plain text file.
    ecs::Entity ball = manager.makeEntity();
        manager.addComponent(ball, std::move(factory.makeCircleShape(10)));
        manager.addComponent(ball, std::move(factory.makePosition(width/2.0, 10)));
        manager.addComponent(ball, std::move(factory.makeSpeed(0,-20)));
        manager.addComponent(ball, std::move(factory.makeBoundingBox(20, 20)));
    ecs::Entity topWall = manager.makeEntity();
        manager.addComponent(topWall, std::move(factory.makeRectangleShape(width,10)));
        manager.addComponent(topWall, std::move(factory.makePosition(0.0, 0.0)));
        manager.addComponent(topWall, std::move(factory.makeBoundingBox(width, 10)));
        manager.addComponent(topWall, std::move(factory.makeSpeed(0.0, 0.0)));
    ecs::Entity botWall = manager.makeEntity();
        manager.addComponent(botWall, std::move(factory.makeRectangleShape(width,10)));
        manager.addComponent(botWall, std::move(factory.makePosition(0.0, height-10)));
        manager.addComponent(botWall, std::move(factory.makeBoundingBox(width, 10)));
        manager.addComponent(botWall, std::move(factory.makeSpeed(0.0, 0.0)));
}

int main(int argc, char ** argv) {
    ecs::Manager manager;
    unsigned int width = 640;
    unsigned int height = 480;

    // Instantiate our game engine
    sf::RenderWindow rWindow(sf::VideoMode(width, height), "SFML Pong Demo");
    Display display(rWindow);
    Engine engine(display);

    // make our entities and add components
    createEntities(manager);

    // Create our systems
    ecs::ptrISystem renderer(new RenderSystem(&rWindow, manager));
    ecs::ptrISystem mover(new PhysicsSystem(manager));
    ecs::ptrISystem collision_detector(new SimpleCollisionSystem(manager));

    // add systems to the game engine
    engine.addSystem(std::move(mover), When::During);
    engine.addSystem(std::move(collision_detector), When::During);
    engine.addSystem(std::move(renderer), When::After);

    // start the main loop
    engine.start();

    return 0;
}
