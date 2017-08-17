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
    unsigned int width = 480;
    unsigned int height = 640;

    // Make our components
    sf::CircleShape ballCircleShape(15);
    ecs::ptrIComponent ballShape(new ShapeComponent(ballCircleShape));
    ecs::ptrIComponent ballPosition(new PositionComponent(0,0));
    ecs::ptrIComponent ballSpeed(new SpeedComponent(0.1,0.1));
    //sf::Vector2f(width, 10);
    //sf::RectangleShape wallShape(size);
    //ecs::ptrIComponent wPtr(new ShapeComponent(wallShape));

    // Make our entities and add the appropriate components.
    ecs::Entity ball = manager.makeEntity();
    manager.addComponent(ball, std::move(ballShape));
    manager.addComponent(ball, std::move(ballPosition));
    manager.addComponent(ball, std::move(ballSpeed));

    // Instantiate our game engine
    sf::RenderWindow rWindow(sf::VideoMode(height, width), "SFML Pong Demo");
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
