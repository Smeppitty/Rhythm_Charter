#include "play_time.h"


Play_Time::Play_Time(sf::Font font, sf::Color fontColor, sf::Vector2f position, int charSize, std::shared_ptr<Music_Player> mp) : GUI_Element(position)
{   
    this->mp = mp;
    this->playTimeText = std::to_string(this->mp->getPlayingPos()) + "/" + std::to_string(this->mp->getDuration());
    this->text = sf::Text(playTimeText, font, charSize);
    this->text.setPosition(position);
    this->text.setFillColor(fontColor);
}

bool Play_Time::isClicked(std::shared_ptr<sf::RenderWindow> window)
{
    return false;
}

void Play_Time::updateText()
{
    this->playTimeText = std::to_string(this->mp->getPlayingPos()) + "/" + std::to_string(this->mp->getDuration());
    this->text.setString(this->playTimeText);
}

void Play_Time::draw(std::shared_ptr<sf::RenderWindow> window)
{  
    window->draw(this->text);
}