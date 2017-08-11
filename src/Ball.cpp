#include "Ball.h"

Ball::Ball(float rad, sf::Vector2f dir)
    : CircleShape(rad), 
      dir(1.0f,0.0f),
      speed(5.0f),
      totalElapsed(0),
      updateInterval(1000)
{};

void Ball::setSpeed(float speed)
{
    this->speed = speed;
}
void Ball::setUpdateInterval(unsigned int interval)
{
    updateInterval = interval;
}

float Ball::getSpeed() const{
    return speed;
}

unsigned int Ball::getUpdateInterval() const{
    return updateInterval;
}

void Ball::collision(eSide which)
{
    switch (which){
        case eSide::top:
            dir.y =  1;
            break;
        case eSide::bottom:
            dir.y = -1;
            break;
        case eSide::left:
            dir.x = 1;
            break;
        case eSide::right:
            dir.x = -1;
            break;
    }
}

void Ball::update(unsigned int elapsed){
    totalElapsed += elapsed;
    if (totalElapsed >= updateInterval)
    {
        totalElapsed = 0;
        sf::Vector2f newDir = dir*speed;
        this->move(dir*speed);
    }
}

