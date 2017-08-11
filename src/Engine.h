#ifndef Engine_HEADER
#define Engine_HEADER

#include <vector>
#include <SFML/Graphics.hpp>
#include "Ball.h"

class Engine
{
    public:
        Engine(int width, int height, std::string name, Ball* ball);
        ~Engine(){};

        void start();

    private:
        void input();
        void update(unsigned int elapsed);
        void draw();

        int width;
        int height;
        sf::RenderWindow rWindow;
        Ball* ball;
        sf::Text text;
        sf::Event event;
        sf::Font font;
};

#endif //Engine_HEADER
