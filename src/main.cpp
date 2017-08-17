// current dir
#include <Engine.h>
#include <Display.h>
#include <Components/ShapeComponent.h>
#include <Components/PositionComponent.h>
#include <Components/SpeedComponent.h>
#include <Systems/RenderSystem.h>
#include <Systems/PhysicsSystem.h>

// local lib
#include <SimpleECS/ISystem.h>
#include <SimpleECS/IComponent.h>
#include <SimpleECS/Manager.h>

// semi-local lib
#include <SFML/Graphics.hpp>

// system lib
#include <memory>
#include <iostream>

int main(int argc, char ** argv) {
    ecs::Manager manager;
    unsigned int width = 640;
    unsigned int height = 480;

    // Make our components
    //     ball
    sf::CircleShape ballCircleShape(15);
    ecs::ptrIComponent ballShape(new ShapeComponent(ballCircleShape));
    ecs::ptrIComponent ballPosition(new PositionComponent(0,0));
    ecs::ptrIComponent ballSpeed(new SpeedComponent(0.1,0.1));
    //     top wall
    sf::Vector2f size(width, 10);
    sf::RectangleShape wall1RectShape(size);
    ecs::ptrIComponent wall1Shape(new ShapeComponent(wall1RectShape));
    ecs::ptrIComponent wall1Pos(new PositionComponent(0,0));
    //     bot wall
    sf::RectangleShape wall2RectShape(size);
    ecs::ptrIComponent wall2Shape(new ShapeComponent(wall2RectShape));
    ecs::ptrIComponent wall2Pos(new PositionComponent(0, height-10));

    // Make our entities and add the appropriate components.
    ecs::Entity ball = manager.makeEntity();
        manager.addComponent(ball, std::move(ballShape));
        manager.addComponent(ball, std::move(ballPosition));
        manager.addComponent(ball, std::move(ballSpeed));
    ecs::Entity topWall = manager.makeEntity();
        manager.addComponent(topWall, std::move(wall1Shape));
        manager.addComponent(topWall, std::move(wall1Pos));
    ecs::Entity botWall = manager.makeEntity();
        manager.addComponent(botWall, std::move(wall2Shape));
        manager.addComponent(botWall, std::move(wall2Pos));

    // Instantiate our game engine
    sf::RenderWindow rWindow(sf::VideoMode(width, height), "SFML Pong Demo");
    Display display(rWindow);
    Engine engine(display);

    // Create our systems
    ecs::ptrISystem renderer(new RenderSystem(&rWindow, manager));
    ecs::ptrISystem mover(new PhysicsSystem(manager));

    // add systems to the game engine
    engine.addSystem(std::move(mover), When::During);
    engine.addSystem(std::move(renderer), When::After);

    // start the main loop
    engine.start();

    return 0;
}
