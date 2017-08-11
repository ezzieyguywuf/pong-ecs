#ifndef Ball_HEADER
#define Ball_HEADER

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
    public:
        Ball(float rad, sf::Vector2f dir);
        ~Ball(){};

        enum class eSide{
            top,
            bottom,
            left,
            right
        };

        void setSpeed(float speed);
        void setUpdateInterval(unsigned int interval);
        float getSpeed() const;
        unsigned int getUpdateInterval() const;

        void collision(eSide which);
        void update(unsigned int elapsed);

    private:
        sf::Vector2f dir;
        float speed;
        unsigned int updateInterval;
        unsigned int totalElapsed;
};

#endif //Ball_HEADER
