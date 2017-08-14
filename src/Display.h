#ifndef Display_HEADER
#define Display_HEADER

#include <SFML/Graphics.hpp>

class Display
{
    public:
        Display(sf::RenderWindow& aWindow);
        bool isOpen() const;
        bool closeRequested();
        void close();

    private:
        sf::RenderWindow& myWindow;
        sf::Event event;
};

#endif //Display_HEADER
