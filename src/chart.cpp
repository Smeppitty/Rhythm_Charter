#include "chart.h"

Chart::Chart(std::shared_ptr<Music_Player> music_player, std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) : GUI_Element(position)
{
    this->chartShape.setPosition(position);
    this->chartShape.setSize(dimensions);

    if(!this->chartTex.loadFromFile(path))
        this->chartShape.setFillColor(fillColor);
    else
        this->chartShape.setTexture(&chartTex);      

    int counter = music_player->getDuration()/60;
    bool checkerCheck = false;

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

    // pixelPos = sf::Mouse::getPosition(*window);
    // worldPos = window->mapPixelToCoords(pixelPos);
    // for(auto square : squareGrid)
    //     {
    //         rect = this->chartShape.getGlobalBounds();

    //         if (rect.contains(worldPos)) 
    //         {
    //             square->setFillColor(sf::Color::Green);
    //             this->Timings.push_back(square->getPosition().x);  


    //             std::cout<< " chart clicked! " << std::endl;
    //             return true;
    //         }
    //         return false; 
    //     }
}

void Chart::draw(std::shared_ptr<sf::RenderWindow> window)
{
    for(auto beat : this->squareGrid)
        window->draw(*beat);
    window->draw(this->chartShape);
}