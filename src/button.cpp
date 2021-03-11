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
                    this->buttonShape.setFillColor(sf::Color(211,211,211,32));
                    this->buttonShape.setFillColor(sf::Color::White);
                    return true;
                }
                else if(this->clickState = false)
                {
                    this->clickState = true;
                    this->buttonShape.setFillColor(sf::Color(211,211,211,32));
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