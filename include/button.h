#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
private:
    sf::RectangleShape buttonShape;
    std::string path;
    sf::Color fillColor;
    sf::Vector2f dimensions;

public:
    Button(std::string path, sf::Color fillColor, sf::Vector2f dimensions);
    ~Button();
};
#endif