#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

#include <SFML/Graphics.hpp>
#include <memory>

class GUI_Element : std::enable_shared_from_this<GUI_Element> 
{
private:
    sf::Vector2f position;
public:
    GUI_Element(sf::Vector2f position);

    virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;
};
#endif