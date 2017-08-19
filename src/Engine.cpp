#include "Engine.h"

//#include <SFML/System.hpp>

Engine::Engine(sf::RenderWindow& aWindow, unsigned int rate)
    : myWindow(aWindow),
      TICK_RATE(rate)
{}

Engine::~Engine()
{}

void Engine::start()
{
    sf::Clock clock;

    unsigned int elapsed = 0;
    // TICK_RATE is ticks/sec. TIME_STEP is "amount of time passed per tick", in other
    // words 1/TICK_RATE. Finally, we must convert from sec/ticks to microsecs/tick
    TIME_STEP = 1000000.0/TICK_RATE;
    unsigned int accumulated = 0;

    while (myWindow.isOpen())
    {
        elapsed = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        accumulated += elapsed;

        this->Input();
        // process as many 'tick's as we can. Any extra will just accumulate until there's
        // a full 'tick' left to process.
        // Example:
        //      TIME_STEP   = 0.1  s
        //      elapsed     = 0.35 s
        //      accumulated = 0.40 s
        //
        //      Notice that accumulated is greater than elapsed. That's because there was
        //      0.05s leftover from the last loop -> we can't process a half a 'tick', so
        //      we just waited until we had a full tick left. Now, since 0.35s has elapsed
        //      in 'real time', we need to advance the game time by 4 'ticks' before
        //      moving on
        while (accumulated >= TIME_STEP)
        {
            this->Update();
            accumulated -= TIME_STEP;
        }
        //This may take a 'long' time
        this->Draw();
    }
}

void Engine::addSystem(ecs::ptrISystem aSystem, const When when)
{
    switch (when){
        case When::Before:
            systemsBefore.push_back(std::move(aSystem));
            break;
        case When::During:
            systemsDuring.push_back(std::move(aSystem));
            break;
        case When::After:
            systemsAfter.push_back(std::move(aSystem));
            break;
    }
}

const std::set<sf::Keyboard::Key>& Engine::getEventsRef() const
{
    return events;
}

//-------------------------------------------------------
//                  private methods
//-------------------------------------------------------

void Engine::processSystems(const ecs::ptrISystems& systems)
{
    for (const auto& system : systems)
    {
        system->Execute(TIME_STEP); 
    }
}

void Engine::Input()
{
    while (myWindow.pollEvent(event))
    {
        events.clear();
        if (event.type == sf::Event::EventType::Closed)
        {
            myWindow.close();
        }
        if (event.type == sf::Event::EventType::KeyPressed){
            events.insert(event.key.code);
        }
    }
    this->processSystems(this->systemsBefore);
}

void Engine::Update()
{
    this->processSystems(this->systemsDuring);
}

void Engine::Draw()
{
    this->processSystems(this->systemsAfter);
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
