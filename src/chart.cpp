#include "chart.h"

Chart::Chart(std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) : GUI_Element(position)
{
    this->chartShape.setPosition(position);
    this->chartShape.setSize(dimensions);

    if(!this->chartTex.loadFromFile(path))
        this->chartShape.setFillColor(fillColor);
    else
        this->chartShape.setTexture(&chartTex);      

    // //create a grid
    // for(auto list : this->squareGrid)

    //     for(auto elements : list)

}

bool Chart::isClicked (std::shared_ptr<sf::RenderWindow> window)
{
rect = this->chartShape.getGlobalBounds();

    pixelPos = sf::Mouse::getPosition(*window);
    worldPos = window->mapPixelToCoords(pixelPos);

        if (rect.contains(worldPos)) 
        {
            

            this->Timings.push_back(worldPos.x);
            std::shared_ptr<sf::RectangleShape> beat = std::make_shared<sf::RectangleShape>();
            beat->setSize(sf::Vector2f(5.0f, 5.0f));
            // beat->setPosition();
            beat->setFillColor(sf::Color::Green);
            this->timedBeats.push_back(beat);

            std::cout<< " chart clicked! " << std::endl;
            return true;
        }
        return false; 
}

void Chart::draw(std::shared_ptr<sf::RenderWindow> window)
{
    for(auto beat : this->timedBeats)
        window->draw(*beat);
    window->draw(this->chartShape);
}