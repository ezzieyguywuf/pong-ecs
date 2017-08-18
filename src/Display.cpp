#include "Display.h"

Display::Display(sf::RenderWindow& aWindow)
    : myWindow(aWindow){}

bool Display::isOpen() const
{
    return myWindow.isOpen();
}

bool Display::closeRequested()
{
    while (myWindow.pollEvent(event))
    {
        if (event.type == sf::Event::EventType::Closed)
        {
            return true;
        }
    }
    return false;
}

void Display::close()
{
    myWindow.close();
}
