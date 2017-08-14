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
    sf::Event event;
    while(rWindow.isOpen())
    {
        while (rWindow.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
            {
                rWindow.close();
            }
        }
        renderer.Execute(ball);
        //rWindow.display();
    }

    return 0;
}
