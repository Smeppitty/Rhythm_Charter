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

    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;
    sf::FloatRect rect;
    
public:
    Textfield(sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions);

    sf::Color getOutlineColor() { return this->txtFieldShape.getOutlineColor(); }

    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);
};
#endif