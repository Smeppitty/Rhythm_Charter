#ifndef CHART_H
#define CHART_H

#include "gui_element.h"
#include "music_player.h"
#include "beat.h"

class Chart : public GUI_Element
{
private:
    sf::RectangleShape chartShape;
    sf::Texture chartTex;

    std::string chartPath;
    sf::Color fillColor;
    sf::Vector2f dimensions;

    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;
    sf::FloatRect rect;

    std::vector<std::shared_ptr<Beat>> beatList;
    std::vector<std::shared_ptr<Beat>> greenList;

    // std::vector<float> beatTimings;
    // std::vector<std::shared_ptr<sf::RectangleShape>> beatSquares;
    // std::vector<std::shared_ptr<sf::RectangleShape>> chartSquares;

public:
    Chart();

    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);
    
    void addBeat(float timing, std::shared_ptr<sf::RectangleShape> rect, std::shared_ptr<sf::RectangleShape> chartBeat);
    void removeBeat(int x);

    std::vector<std::shared_ptr<Beat>> getBeatList() { return this->beatList; }

};

#endif