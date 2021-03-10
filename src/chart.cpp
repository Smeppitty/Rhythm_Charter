#include "chart.h"

Chart::Chart(std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) : GUI_Element(position)
{
    this->chartShape.setPosition(position);
    this->chartShape.setSize(dimensions);

    if(!this->chartTex.loadFromFile(path))
        this->chartShape.setFillColor(fillColor);
    else
        this->chartShape.setTexture(&chartTex);      
}

bool Chart::isClicked (std::shared_ptr<sf::RenderWindow> window)
{
    return false;
}

void Chart::draw(std::shared_ptr<sf::RenderWindow> window)
{

}