#include "textfield.h"

Textfield::Textfield(sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) : GUI_Element(position)
{
    this->position = position;
    this->fillColor = fillColor;
    this->dimensions = dimensions;

    this->txtFieldShape.setPosition(position);
    this->txtFieldShape.setSize(dimensions);
    this->txtFieldShape.setFillColor(fillColor);
    this->txtFieldShape.setOutlineThickness(3.0f);
    this->txtFieldShape.setOutlineColor(sf::Color::Transparent);
}

bool Textfield::isClicked(std::shared_ptr<sf::RenderWindow> window)
{
    rect = this->txtFieldShape.getGlobalBounds();

    pixelPos = sf::Mouse::getPosition(*window);
    worldPos = window->mapPixelToCoords(pixelPos);

        if (rect.contains(worldPos)) 
            {   
                this->txtFieldShape.setOutlineColor(sf::Color::Blue);
                isInside = true;
                return true;
            }
        this->txtFieldShape.setOutlineColor(sf::Color::Transparent);
        isInside = false;
        return false; 
}
void Textfield::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(txtFieldShape);
}