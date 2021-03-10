#ifndef CHART_H
#define CHART_H

#include "gui_element.h"

class Chart : public GUI_Element
{
private:
    sf::RectangleShape chartShape;
    sf::Texture chartTex;

    std::string chartPath;
    sf::Color fillColor;
    sf::Vector2f dimensions;

public:
    Chart(std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions);

    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);
};

#endif