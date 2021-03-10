#include "button.h"

Button::Button(std::string path, sf::Color fillColor, sf::Vector2f dimensions)
{
    this->path = path;
    this->fillColor = fillColor;
    this->dimensions = dimensions;
    if(path == NULL)
        
}

Button::~Button()
{
}
