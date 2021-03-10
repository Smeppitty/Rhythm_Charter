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
    sf::FloatRect rect = this->buttonShape.getGlobalBounds();

    sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);

        if (rect.contains(worldPos)) {
            {   
                this->buttonShape.setFillColor(sf::Color(211,211,211,32));
                return true;
            }
        }
        return false; 
}

void Button::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->buttonShape);
}