#ifndef PLAY_TIME_H
#define PLAY_TIME_H

#include "gui_element.h"

class Play_Time : public GUI_Element
{
private:
    sf::Text text;
public:
    Play_Time(sf::Font font, sf::Color fontColor, sf::Vector2f position, int charSize);
    
    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);

    void setText(std::string text);
    
};
#endif