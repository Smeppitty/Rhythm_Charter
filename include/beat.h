#ifndef BEAT_H
#define BEAT_H

#include "gui_element.h"

class Beat : public GUI_Element
{
private:
    float beatTiming;
    std::shared_ptr<sf::RectangleShape> beatSquare;
    std::shared_ptr<sf::RectangleShape> chartSquare;

    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;

public:
    Beat(float beatTiming, std::shared_ptr<sf::RectangleShape> beatSquare, std::shared_ptr<sf::RectangleShape> chartSquare);

    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);

    float getTiming() { return this->beatTiming; }
    std::shared_ptr<sf::RectangleShape> getChartSquare() { return this->chartSquare; }


};


#endif