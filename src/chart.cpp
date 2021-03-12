#include "chart.h"

Chart::Chart(std::shared_ptr<Music_Player> music_player, std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) : GUI_Element(position)
{
    // this->chartShape.setPosition(position);
    // this->chartShape.setSize(dimensions);

    // if(!this->chartTex.loadFromFile(path))
    //     this->chartShape.setFillColor(fillColor);
    // else
    //     this->chartShape.setTexture(&chartTex);      

    // int counter = music_player->getDuration()/60;
    // bool checkerCheck = false;

    //create a grid
    // for(int i = 1; i < 5; i++)
    //     for(int j = 0; j < dimensions.x; j+=counter)
    //         {
    //             std::shared_ptr<sf::RectangleShape> beat = std::make_shared<sf::RectangleShape>();
    //             beat->setSize(sf::Vector2f(60.0f, 60.0f));
    //             beat->setOrigin(sf::Vector2f(30.0f, 30.0f));
    //             beat->setPosition(sf::Vector2f(j, dimensions.y/5));
    //             if(checkerCheck)
    //             {
    //                 beat->setFillColor(sf::Color(211,211,211,32));
    //             }
    //             if(!checkerCheck)
    //             {
    //                 beat->setFillColor(sf::Color::White);
    //             }
    //             this->squareGrid.push_back(beat);
    //         }

    // for(auto list : this->squareGrid)
    //     for(auto elements : list)

}

bool Chart::isClicked (std::shared_ptr<sf::RenderWindow> window)
{

}

void Chart::addBeat(std::shared_ptr<sf::RectangleShape> chartBeat, std::shared_ptr<sf::RectangleShape> rect, float timing)
{ 
    this->chartSquares.push_back(chartBeat);
    this->beatSquares.push_back(rect); 
    this->beatTimings.push_back(timing); 
}

void Chart::removeBeat()
{

}


void Chart::draw(std::shared_ptr<sf::RenderWindow> window)
{
    for(auto beat : this->beatSquares)
        window->draw(*beat);
    
    for(auto square : this->chartSquares)
        window->draw(*square);    

    window->draw(this->chartShape);
}