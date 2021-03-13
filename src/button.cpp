#include "button.h"

Button::Button(std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) :GUI_Element()
{   
    this->position = position;
    this->path = path;
    this->fillColor = fillColor;
    this->dimensions = dimensions;

    this->buttonShape.setPosition(position);
    this->buttonShape.setSize(dimensions);
    this->buttonShape.setOutlineColor(sf::Color::Transparent);
    this->buttonShape.setOutlineThickness(15);

    if(!this->buttonTex.loadFromFile(path))
        this->buttonShape.setFillColor(fillColor);
    else
        this->buttonShape.setTexture(&buttonTex);            
}
bool Button::isClicked(std::shared_ptr<sf::RenderWindow> window)
{
    rect = this->buttonShape.getGlobalBounds();

    pixelPos = sf::Mouse::getPosition(*window);
    worldPos = window->mapPixelToCoords(pixelPos);

        if (rect.contains(worldPos)) {
            {   
                if(this->clickState = true)
                {   
                    this->clickState = false;
                    this->buttonShape.setOutlineColor(sf::Color::Transparent);
                    return true;
                }
                else if(this->clickState = false)
                {
                    this->clickState = true;
                    this->buttonShape.setOutlineColor(sf::Color(246,171,252));
                    return true;
                }
            }
        }
        return false; 
}

void Button::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->buttonShape);
}