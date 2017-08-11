#include "Engine.h"

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

Engine::Engine(int width, int height, std::string name, Ball* ball)
    : width(width), 
      height(height),
      rWindow(sf::VideoMode(width, height), name),
      ball(ball)
{
    if (!font.loadFromFile("DejaVuSansMono.ttf"))
    {
        std::cout << "unable to load font" << std::endl;
    }
    this->text.setFont(font);
    this->text.setCharacterSize(14);
    this->text.setFillColor(sf::Color::White);
}

void Engine::start()
{
    sf::Clock clock;

    while (rWindow.isOpen())
    {
        unsigned int elapsed = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        this->input();
        this->update(elapsed);
        this->draw();
    }
}

void Engine::input()
{
    while (rWindow.pollEvent(event))
    {
        if (event.type == sf::Event::EventType::Closed)
        {
            rWindow.close();
        }
        if (event.type == sf::Event::EventType::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
                ball->setSpeed(ball->getSpeed() + 0.1);
            if (event.key.code == sf::Keyboard::Down)
                ball->setSpeed(ball->getSpeed() - 0.1);
            if (event.key.code == sf::Keyboard::Left)
                ball->setUpdateInterval(ball->getUpdateInterval() - 10);
            if (event.key.code == sf::Keyboard::Right)
                ball->setUpdateInterval(ball->getUpdateInterval() + 10);
        }
    }
}

void Engine::update(unsigned int elapsed)
{
    // first, check for collisions
    sf::FloatRect bbox = ball->getGlobalBounds();
    if (bbox.left + bbox.width >= width)
        ball->collision(Ball::eSide::right);
    if (bbox.top + bbox.height >= height)
        ball->collision(Ball::eSide::bottom);
    if (bbox.left <= 0)
        ball->collision(Ball::eSide::left);
    if (bbox.top <= 0)
        ball->collision(Ball::eSide::top);

    // update the location
    ball->update(elapsed);

    // move if beyond screen bounds
    //bbox = ball->getGlobalBounds();
    //if (bbox.left + bbox.width >= width)
        //ball->setPosition(width - bbox.width, bbox.top);
    //if (bbox.top + bbox.height >= height)
        //ball->setPosition(bbox.left, height - bbox.height);
    //if (bbox.left <= 0)
        //ball->setPosition(0, bbox.top);
    //if (bbox.top <= 0)
        //ball->setPosition(bbox.left, 0);

    // print out data
    std::ostringstream pos;
    pos << "x = " << bbox.left << ", y = " << bbox.top << std::endl;
    pos << "speed = " << ball->getSpeed() << ", updateInterval = " << ball->getUpdateInterval();
    //std::cout << pos.str() << std::endl;
    this->text.setString(pos.str());
}

void Engine::draw()
{
    // clear the screen and set it to our new color
    rWindow.clear();
    rWindow.draw(*ball);
    rWindow.draw(this->text);
    rWindow.display();
}
