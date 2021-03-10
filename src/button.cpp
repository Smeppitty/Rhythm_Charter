#include "button.h"

Button::Button(std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) :GUI_Element(position)
{   
    this->position = position;
    this->path = path;
    this->fillColor = fillColor;
    this->dimensions = dimensions;

    this->buttonShape.setPosition(position);
    this->buttonShape.setSize(dimensions);

    if(!this->buttonTex.loadFromFile(path))
        this->buttonShape.setFillColor(fillColor);
    else
        this->buttonShape.setTexture(&buttonTex);     
        
}

void Button::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->buttonShape);
}