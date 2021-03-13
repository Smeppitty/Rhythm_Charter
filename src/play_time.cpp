#include "play_time.h"


Play_Time::Play_Time(sf::Font font, sf::Color fontColor, sf::Vector2f position, int charSize, std::shared_ptr<Music_Player> mp) : GUI_Element()
{   
    this->mp = mp;
    this->playTimeText = "0:00 / 0:00";

    this->text = sf::Text(this->playTimeText, font, charSize);
    this->text.setPosition(position);
    this->text.setFillColor(fontColor);
}

bool Play_Time::isClicked(std::shared_ptr<sf::RenderWindow> window)
{
    return false;
}

void Play_Time::draw(std::shared_ptr<sf::RenderWindow> window)
{  
    this->updateText();
    // window->draw(this->text);
}

void Play_Time::updateText()
{   
    now = this->mp->getPlayingPos();
    duration = this->mp->getDuration();
    this->playTimeText = std::to_string(now/60) + ":" + std::to_string(now%60) + " / " 
    + std::to_string(duration/60) + ":" + std::to_string(duration%60);
    this->text.setString(this->playTimeText);
}
