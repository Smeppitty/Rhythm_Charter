#include "play_time.h"


Play_Time::Play_Time(sf::Font font, sf::Color fontColor, sf::Vector2f position, int charSize) : GUI_Element(position)
{
    this->text = sf::Text("", font, charSize);
    this->text.setPosition(position);
}

bool Play_Time::isClicked(std::shared_ptr<sf::RenderWindow> window)
{
    return false;
}

void Play_Time::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->text);
}