#include <iostream>

#include "Engine.h"
#include "Ball.h"

#include <random>

int main(int argc, char ** argv) {

    // this will be used to generate random numbers
    std::uniform_int_distribution<int> randomColorRange(0, 255);
    std::random_device rd;
    std::mt19937 randomNumbers(rd());

    std::uniform_real_distribution<float> rndXRange(-1, 1);
    std::uniform_real_distribution<float> rndYRange(-0.5, 0.5);

    sf::Vector2f initDir;
    initDir.x = rndXRange(randomNumbers);
    initDir.y = rndYRange(randomNumbers);

    Ball myBall(15, initDir);

    Engine myEngine(640, 480, "SFML pong", &myBall);
    myEngine.start();
    return 0;
}
