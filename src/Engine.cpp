#include "Engine.h"

//#include <SFML/System.hpp>

void Engine::start()
{
    sf::Clock clock;

    // one 'tick' per 0.01 seconds
    unsigned int elapsed = 0;
    unsigned int time_step = 10000;
    unsigned int accumulated = 0;

    while (myDisplay.isOpen())
    {
        elapsed = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        accumulated += elapsed;

        this->Input();
        // process as many 'tick's as we can. Any extra will just accumulate until there's
        // a full 'tick' left to process.
        // Example:
        //      time_step   = 0.1  s
        //      elapsed     = 0.35 s
        //      accumulated = 0.40 s
        //
        //      Notice that accumulated is greater than elapsed. That's because there was
        //      0.05s leftover from the last loop -> we can't process a half a 'tick', so
        //      we just waited until we had a full tick left. Now, since 0.35s has elapsed
        //      in 'real time', we need to advance the game time by 4 'ticks' before
        //      moving on
        while (accumulated >= time_step)
        {
            this->Update();
            accumulated -= time_step;
        }
        //This may take a 'long' time
        this->Draw();
    }
}

void Engine::Input()
{
    if (myDisplay.closeRequested())
        myDisplay.close();
}

void Engine::Update()
{
}

void Engine::Draw()
{
    //RenderSystem.Execute(anEntity);
}

//void Engine::input()
//{
    //while (rWindow.pollEvent(event))
    //{
        //if (event.type == sf::Event::EventType::Closed)
        //{
            //rWindow.close();
        //}
        //if (event.type == sf::Event::EventType::KeyPressed)
        //{
            //if (event.key.code == sf::Keyboard::Up) {
                //ball->setSpeed(ball->getSpeed() + 0.01*mult);
            //}
            //if (event.key.code == sf::Keyboard::Down){
                //ball->setSpeed(ball->getSpeed() - 0.01*mult);
            //}
            //if (event.key.code == sf::Keyboard::Left){
                //ball->setUpdateInterval(ball->getUpdateInterval() - 100*mult);
            //}
            //if (event.key.code == sf::Keyboard::Right){
                //ball->setUpdateInterval(ball->getUpdateInterval() + 100*mult);
            //}
        //}
    //}
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    //{
        //mult = 10;
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            //mult = 100;
    //}
    //else {
        //mult = 1;
    //}
//}

//void Engine::update(unsigned int elapsed)
//{
    //// first, check for collisions
    //sf::FloatRect bbox = ball->getGlobalBounds();
    //if (bbox.left + bbox.width >= width)
        //ball->collision(Ball::eSide::right);
    //if (bbox.top + bbox.height >= height)
        //ball->collision(Ball::eSide::bottom);
    //if (bbox.left <= 0)
        //ball->collision(Ball::eSide::left);
    //if (bbox.top <= 0)
        //ball->collision(Ball::eSide::top);

    //// update the location
    //ball->update(elapsed);

    //// move if beyond screen bounds
    ////bbox = ball->getGlobalBounds();
    ////if (bbox.left + bbox.width >= width)
        ////ball->setPosition(width - bbox.width, bbox.top);
    ////if (bbox.top + bbox.height >= height)
        ////ball->setPosition(bbox.left, height - bbox.height);
    ////if (bbox.left <= 0)
        ////ball->setPosition(0, bbox.top);
    ////if (bbox.top <= 0)
        ////ball->setPosition(bbox.left, 0);

    //// print out data
    //std::ostringstream pos;
    //pos << "x = " << bbox.left << ", y = " << bbox.top << std::endl;
    //pos << "speed = " << ball->getSpeed() << ", updateInterval = " << ball->getUpdateInterval() << std::endl;
    //pos << "mult = " << this->mult;
    ////std::cout << pos.str() << std::endl;
    //this->text.setString(pos.str());
//}

//void Engine::draw()
//{
    //// clear the screen and set it to our new color
    //rWindow.clear();
    //rWindow.draw(*ball);
    //rWindow.draw(this->text);
    //rWindow.display();
//}
