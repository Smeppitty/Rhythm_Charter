#include "chart.h"

Chart::Chart(std::shared_ptr<Music_Player> music_player, std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) : GUI_Element(position)
{
    
}

bool Chart::isClicked (std::shared_ptr<sf::RenderWindow> window)
{

    //check for a square in chartSquares

    //add an outline around it
    //make certain inputs the user can do to delete or drag a square to
    return true;
}

void Chart::addBeat(std::shared_ptr<sf::RectangleShape> chartBeat, std::shared_ptr<sf::RectangleShape> rect, float timing)
{ 
    this->chartSquares.push_back(chartBeat);
    this->beatSquares.push_back(rect); 
    this->beatTimings.push_back(timing); 
}

void Chart::removeBeat(int x)
{
    std::vector<float>::iterator iter = this->beatTimings.begin() + (x-1);
    std::vector<std::shared_ptr<sf::RectangleShape>>::iterator beatIter1 = this->beatSquares.begin() + (x-1);
    std::vector<std::shared_ptr<sf::RectangleShape>>::iterator beatIter2 = this->chartSquares.begin() + (x-1);

    this->beatTimings.erase(iter);
    this->beatSquares.erase(beatIter1);
    this->chartSquares.erase(beatIter2);
}


void Chart::draw(std::shared_ptr<sf::RenderWindow> window)
{
    for(auto beat : this->beatSquares)
        window->draw(*beat);
    
    for(auto square : this->chartSquares)
        window->draw(*square);    

    window->draw(this->chartShape);
}