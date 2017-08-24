// current dir
#include <Engine.h>

#include <Components/ComponentFactory.h>

#include <Systems/RenderSystem.h>
#include <Systems/PhysicsSystem.h>
#include <Systems/EventCollisionSystem.h>
#include <Systems/TextSinkRenderSystem.h>
#include <Systems/InputHandlerSystem.h>
#include <Systems/EventCollisionSystem.h>

// local lib
#include <SimpleECS/ISystem.h>
#include <SimpleECS/IComponent.h>
#include <SimpleECS/Manager.h>
#include <Events/EventManager.h>

// semi-local lib
#include <SFML/Window.hpp>

// system lib
#include <memory>
#include <iostream>

float WIDTH = 640;
float HEIGHT = 480;

using std::move;
using Key = sf::Keyboard::Key;

void createEntities(ecs::Manager& manager, sf::RenderWindow& rWindow, sf::Font& font)
{
    ComponentFactory factory;
    // Make our entities and add the appropriate components.
    // NOTE: this could be pulled, theoretically, from some sort of plain text file.
    ecs::Entity ball = manager.makeEntity();
        manager.addComponent(ball, move(factory.makeCircleShape(10)));
        manager.addComponent(ball, move(factory.makePosition(WIDTH/2.0, 80)));
        manager.addComponent(ball, move(factory.makeSpeed(0,-1.5)));
        manager.addComponent(ball, move(factory.makeBoundingBox(20, 20)));
        manager.addComponent(ball, move(factory.makeCollidable()));
        manager.addComponent(ball, move(factory.makeBounce()));
    ecs::Entity ball2 = manager.makeEntity();
        manager.addComponent(ball2, move(factory.makeCircleShape(10)));
        manager.addComponent(ball2, move(factory.makePosition(WIDTH/2.0 - 80, 80)));
        manager.addComponent(ball2, move(factory.makeSpeed(0.0,0.0)));
        manager.addComponent(ball2, move(factory.makeBoundingBox(20, 20)));
        manager.addComponent(ball2, move(factory.makeMovable(Key::Up, Key::Down, Key::Left, Key::Right)));
        manager.addComponent(ball2, move(factory.makeCollidable()));
        manager.addComponent(ball2, move(factory.makeBounce()));
    ecs::Entity ball3 = manager.makeEntity();
        manager.addComponent(ball3, move(factory.makeCircleShape(10)));
        manager.addComponent(ball3, move(factory.makePosition(WIDTH/2.0 + 80, 80)));
        manager.addComponent(ball3, move(factory.makeSpeed(0,-1)));
        manager.addComponent(ball3, move(factory.makeBoundingBox(20, 20)));
        manager.addComponent(ball3, move(factory.makeCollidable()));
        manager.addComponent(ball3, move(factory.makeBounce()));
    ecs::Entity lPaddle = manager.makeEntity();
        manager.addComponent(lPaddle, move(factory.makeRectangleShape(10,80)));
        manager.addComponent(lPaddle, move(factory.makePosition(15.0, HEIGHT/2.0 - 40)));
        manager.addComponent(lPaddle, move(factory.makeBoundingBox(10, 80)));
        manager.addComponent(lPaddle, move(factory.makeCollidable()));
        manager.addComponent(lPaddle, move(factory.makeMovable(Key::Comma, Key::O, Key::Unknown, Key::Unknown)));
        manager.addComponent(lPaddle, move(factory.makeBounce()));
        manager.addComponent(lPaddle, move(factory.makeSpeed(0.0, 0.0)));
    ecs::Entity rPaddle = manager.makeEntity();
        manager.addComponent(rPaddle, move(factory.makeRectangleShape(10,80)));
        manager.addComponent(rPaddle, move(factory.makePosition(WIDTH - 25.0, HEIGHT/2.0 - 40)));
        manager.addComponent(rPaddle, move(factory.makeBoundingBox(10, 80)));
        manager.addComponent(rPaddle, move(factory.makeCollidable()));
        manager.addComponent(rPaddle, move(factory.makeMovable(Key::C, Key::T, Key::Unknown, Key::Unknown)));
        manager.addComponent(rPaddle, move(factory.makeBounce()));
        manager.addComponent(rPaddle, move(factory.makeSpeed(0.0, 0.0)));
    ecs::Entity topWall = manager.makeEntity();
        manager.addComponent(topWall, move(factory.makeRectangleShape(WIDTH,10)));
        manager.addComponent(topWall, move(factory.makePosition(0.0, 0.0)));
        manager.addComponent(topWall, move(factory.makeBoundingBox(WIDTH, 10)));
        manager.addComponent(topWall, move(factory.makeCollidable()));
        manager.addComponent(topWall, move(factory.makeWall(false)));
    ecs::Entity botWall = manager.makeEntity();
        manager.addComponent(botWall, move(factory.makeRectangleShape(WIDTH,10)));
        manager.addComponent(botWall, move(factory.makePosition(0.0, HEIGHT-10)));
        manager.addComponent(botWall, move(factory.makeBoundingBox(WIDTH, 10)));
        manager.addComponent(botWall, move(factory.makeCollidable()));
        manager.addComponent(botWall, move(factory.makeWall(false)));
    ecs::Entity lftWall = manager.makeEntity();
        manager.addComponent(lftWall, move(factory.makeRectangleShape(10,HEIGHT)));
        manager.addComponent(lftWall, move(factory.makePosition(0.0, 0.0)));
        manager.addComponent(lftWall, move(factory.makeBoundingBox(10, HEIGHT)));
        manager.addComponent(lftWall, move(factory.makeCollidable()));
        manager.addComponent(lftWall, move(factory.makeWall()));
    ecs::Entity rgtWall = manager.makeEntity();
        manager.addComponent(rgtWall, move(factory.makeRectangleShape(10,HEIGHT)));
        manager.addComponent(rgtWall, move(factory.makePosition(WIDTH-10, 0.0)));
        manager.addComponent(rgtWall, move(factory.makeBoundingBox(10, HEIGHT)));
        manager.addComponent(rgtWall, move(factory.makeCollidable()));
        manager.addComponent(rgtWall, move(factory.makeWall()));
    ecs::Entity posText = manager.makeEntity();
        manager.addComponent(posText, move(factory.makeTextShape(font)));
        manager.addComponent(posText, move(factory.makePosition(10.0, 10.0)));
        manager.addComponent(posText, move(factory.makeSpeed(0.0, 0.0)));
    ecs::Entity showText = manager.makeEntity();
        manager.addComponent(showText, move(factory.makeTextSink(posText)));
        manager.addComponent(showText, move(factory.makeTextSource(ball2)));
}

int main(int argc, char ** argv) {
    ecs::Manager manager;
    Event::EventManager eventManager;

    // Instantiate our game engine
    sf::RenderWindow rWindow(sf::VideoMode(WIDTH, HEIGHT), "SFML Pong Demo");
    //rWindow.setFramerateLimit(60);
    Engine engine(rWindow, 30);

    // need a font object
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/dejavu/DejaVuSansMono.ttf")){
        std::cout << "THERE WAS AN ERROR LOADING TEH FONT" << std::endl;
        return 1;
    }

    // make our entities and add components
    createEntities(manager, rWindow, font);

    // add systems to the game engine
    engine.addSystem(
        move(ecs::ptrISystem(new InputHandlerSystem(manager, eventManager))), 
        When::During);
    engine.addSystem(
        move(ecs::ptrISystem(new PhysicsSystem(manager, eventManager))), 
        When::During);
    engine.addSystem(
        move(ecs::ptrISystem(new EventCollisionSystem(manager, eventManager))), 
        When::During);
    engine.addSystem(
        move(ecs::ptrISystem(new TextSinkRenderSystem(manager))), 
        When::During);
    engine.addSystem(
        move(ecs::ptrISystem(new RenderSystem(manager, &rWindow))), 
        When::After);

    // start the main loop
    engine.start();

    return 0;
}
