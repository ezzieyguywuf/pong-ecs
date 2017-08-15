#include "Engine.h"
#include "Common.h"
#include "Display.h"
#include "SFML/Graphics.hpp"
#include "ecs/ISystem.h"
#include "ecs/IComponent.h"
#include "ecs/Manager.h"
#include <memory>

int main(int argc, char ** argv) {
    ecs::Manager manager;

    sf::CircleShape ballShape(5);
    RenderComponent* rComp = new  RenderComponent(&ballShape);

    manager.makeEntity(std::move(std::unique_ptr<ecs::IComponent>(rComp)));

    sf::RenderWindow rWindow(sf::VideoMode(640, 480), "SFML Pong Demo");
    Display display(rWindow);

    ISystem* renderer = new RenderSystem(&rWindow);

    Engine engine(display);
    engine.start();

    delete rComp;
    return 0;
}
