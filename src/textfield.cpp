#include "textfield.h"

Textfield::Textfield(sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) : GUI_Element(position)
{
    this->position = position;
    this->fillColor = fillColor;
    this->dimensions = dimensions;

    this->txtFieldShape.setPosition(position);
    this->txtFieldShape.setSize(dimensions);
    this->txtFieldShape.setFillColor(fillColor);
}

bool Textfield::isClicked(std::shared_ptr<sf::RenderWindow> window)
{
    sf::FloatRect rect = this->txtFieldShape.getGlobalBounds();

    sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);

        if (rect.contains(worldPos)) {
            {   
                this->txtFieldShape.setOutlineColor(sf::Color(211,211,211,32));
                return true;
            }
        }
        return false; 
}

void Textfield::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(txtFieldShape);
}