#ifndef CHART_H
#define CHART_H

#include "gui_element.h"
#include "music_player.h"

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

    std::vector<float> beatTimings;
    std::vector<std::shared_ptr<sf::RectangleShape>> beatSquares;
    std::vector<std::shared_ptr<sf::RectangleShape>> chartSquares;

public:
    Chart(std::shared_ptr<Music_Player> music_player, std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions);

    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);
    
    void addBeat(std::shared_ptr<sf::RectangleShape> chartBeat, std::shared_ptr<sf::RectangleShape> rect, float timing);
    void removeBeat(int x);

    std::vector<float> getTimings() { return this->beatTimings; }
    std::vector<std::shared_ptr<sf::RectangleShape>> getBeats() { return this->beatSquares; }

};

#endif