#ifndef PLAY_TIME_H
#define PLAY_TIME_H

#include "gui_element.h"
#include "music_player.h"

class Play_Time : public GUI_Element
{
private:
    sf::Text text;
    std::string playTimeText;
    std::shared_ptr<Music_Player> mp;

    int now;
    int duration;

public:
    Play_Time(sf::Font font, sf::Color fontColor, sf::Vector2f position, int charSize, std::shared_ptr<Music_Player> mp);
    
    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);

    void updateText();
    
};
#endif