#include "Entity.h"
#include "Common.h"
#include "SFML/Graphics.hpp"

int main(int argc, char ** argv) {
    Entity ball("ball");

    sf::CircleShape ballShape(5);
    RenderComponent rComp(&ballShape);

    ball.components.push_back(&rComp);

    sf::RenderWindow rWindow(sf::VideoMode(640, 480), "SFML Pong Demo");

    RenderSystem renderer(&rWindow);

    renderer.Execute(ball);
    return 0;
}
