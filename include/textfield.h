#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "gui_element.h"

class Textfield : public GUI_Element
{
private:
    sf::Vector2f position;
    sf::RectangleShape txtFieldShape;

    std::string path;
    sf::Color fillColor;
    sf::Vector2f dimensions;
    
public:
    Textfield(sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions);
    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);
};
#endif