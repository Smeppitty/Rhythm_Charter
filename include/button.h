#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <memory>
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

public:
    Button(std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions); 

    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);
};
#endif