#include "beat.h"


Beat::Beat(float beatTiming, std::shared_ptr<sf::RectangleShape> beatSquare, std::shared_ptr<sf::RectangleShape> chartSquare) : GUI_Element()
{
    this->beatTiming = beatTiming;
    this->beatSquare = beatSquare;
    this->chartSquare = chartSquare;
}

bool Beat::isClicked(std::shared_ptr<sf::RenderWindow> window)
{
    return true;
}

void Beat::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(*this->beatSquare);
    window->draw(*this->chartSquare);
}