// current dir
#include <Engine.h>
#include <Display.h>

#include <Components/ComponentFactory.h>

#include <Systems/RenderSystem.h>
#include <Systems/PhysicsSystem.h>
#include <Systems/SimpleCollisionSystem.h>
#include <Systems/TextSinkRenderSystem.h>

// local lib
#include <SimpleECS/ISystem.h>
#include <SimpleECS/IComponent.h>
#include <SimpleECS/Manager.h>

// semi-local lib

// system lib
#include <memory>
#include <iostream>

float WIDTH = 640;
float HEIGHT = 480;

using std::move;

void createEntities(ecs::Manager& manager, sf::RenderWindow& rWindow, sf::Font& font)
{
    ComponentFactory factory;
    // Make our entities and add the appropriate components.
    // NOTE: this could be pulled, theoretically, from some sort of plain text file.
    ecs::Entity ball = manager.makeEntity();
        manager.addComponent(ball, move(factory.makeCircleShape(10)));
        manager.addComponent(ball, move(factory.makePosition(WIDTH/2.0, 80)));
        manager.addComponent(ball, move(factory.makeSpeed(0,-5)));
        manager.addComponent(ball, move(factory.makeBoundingBox(20, 20)));
        manager.addComponent(ball, move(factory.makeRenderWindow(rWindow)));
    ecs::Entity ball2 = manager.makeEntity();
        manager.addComponent(ball2, move(factory.makeCircleShape(10)));
        manager.addComponent(ball2, move(factory.makePosition(WIDTH/2.0 - 80, 80)));
        manager.addComponent(ball2, move(factory.makeSpeed(0,-10)));
        manager.addComponent(ball2, move(factory.makeBoundingBox(20, 20)));
        manager.addComponent(ball2, move(factory.makeRenderWindow(rWindow)));
    ecs::Entity ball3 = manager.makeEntity();
        manager.addComponent(ball3, move(factory.makeCircleShape(10)));
        manager.addComponent(ball3, move(factory.makePosition(WIDTH/2.0 + 80, 80)));
        manager.addComponent(ball3, move(factory.makeSpeed(0,-15)));
        manager.addComponent(ball3, move(factory.makeBoundingBox(20, 20)));
        manager.addComponent(ball3, move(factory.makeRenderWindow(rWindow)));
    ecs::Entity topWall = manager.makeEntity();
        manager.addComponent(topWall, move(factory.makeRectangleShape(WIDTH,10)));
        manager.addComponent(topWall, move(factory.makePosition(0.0, 0.0)));
        manager.addComponent(topWall, move(factory.makeBoundingBox(WIDTH, 10)));
        manager.addComponent(topWall, move(factory.makeSpeed(0.0, 0.0)));
        manager.addComponent(topWall, move(factory.makeRenderWindow(rWindow)));
    ecs::Entity botWall = manager.makeEntity();
        manager.addComponent(botWall, move(factory.makeRectangleShape(WIDTH,10)));
        manager.addComponent(botWall, move(factory.makePosition(0.0, HEIGHT-10)));
        manager.addComponent(botWall, move(factory.makeBoundingBox(WIDTH, 10)));
        manager.addComponent(botWall, move(factory.makeSpeed(0.0, 0.0)));
        manager.addComponent(botWall, move(factory.makeRenderWindow(rWindow)));
    ecs::Entity posText = manager.makeEntity();
        manager.addComponent(posText, move(factory.makeTextShape(font)));
        manager.addComponent(posText, move(factory.makePosition(10.0, 10.0)));
        manager.addComponent(posText, move(factory.makeSpeed(0.0, 0.0)));
        manager.addComponent(posText, move(factory.makeRenderWindow(rWindow)));
    ecs::Entity showText = manager.makeEntity();
        manager.addComponent(showText, move(factory.makeTextSink(posText)));
        manager.addComponent(showText, move(factory.makeTextSource(ball)));
}

int main(int argc, char ** argv) {
    ecs::Manager manager;

    // Instantiate our game engine
    sf::RenderWindow rWindow(sf::VideoMode(WIDTH, HEIGHT), "SFML Pong Demo");
    Display display(rWindow);
    Engine engine(display, 20);

    // need a font object
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/dejavu/DejaVuSansMono.ttf")){
        std::cout << "THERE WAS AN ERROR LOADING TEH FONT" << std::endl;
        return 1;
    }

    // make our entities and add components
    createEntities(manager, rWindow, font);

    // Create our systems
    ecs::ptrISystem renderer(new RenderSystem(manager, &rWindow));
    ecs::ptrISystem mover(new PhysicsSystem(manager));
    ecs::ptrISystem collision_detector(new SimpleCollisionSystem(manager));
    ecs::ptrISystem textSinkRenderer(new TextSinkRenderSystem(manager));

    // add systems to the game engine
    engine.addSystem(move(mover), When::During);
    engine.addSystem(move(collision_detector), When::During);
    engine.addSystem(move(textSinkRenderer), When::During);
    engine.addSystem(move(renderer), When::After);

    // start the main loop
    engine.start();

    return 0;
}
