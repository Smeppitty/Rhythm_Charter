#ifndef BUTTON_H
#define BUTTON_H

#include <string>

#include "gui_element.h"

class Button : public GUI_Element
{
private:
    sf::Vector2f position;
    sf::RectangleShape buttonShape;
    sf::Texture buttonTex;

    std::string path;
    sf::Color fillColor;
    sf::Vector2f dimensions;

    sf::FloatRect rect;

    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;

    bool clickState = false;

public:
    Button(std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions); 

    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);
};
#endif