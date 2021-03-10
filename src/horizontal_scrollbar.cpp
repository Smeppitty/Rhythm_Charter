#include "horizontal_scrollbar.h"

Horizontal_Scrollbar::Horizontal_Scrollbar(std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) : GUI_Element(position)
{
    this->position = position;
    this->path = path;
    this->fillColor = fillColor;
    this->dimensions = dimensions;

    this->horizShape.setPosition(position);
    this->horizShape.setSize(dimensions);

    if(!this->horizTex.loadFromFile(path))
        this->horizShape.setFillColor(fillColor);
    else
        this->horizShape.setTexture(&horizTex);    


    /*
    / Slider in the scrollbar
    */
    this->thumb.setRadius(this->dimensions.y/2);
    this->thumb.setPosition(this->position.x, this->position.y+this->thumb.getRadius());
    this->thumb.setOrigin(this->thumb.getRadius(), this->thumb.getRadius());
}

bool Horizontal_Scrollbar::isClicked(std::shared_ptr<sf::RenderWindow> window)
{
    return false;
}


void Horizontal_Scrollbar::scroll(std::shared_ptr<sf::RenderWindow> window)
{

}


void Horizontal_Scrollbar::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->horizShape);
    window->draw(this->thumb);
}