#include "chart.h"

Chart::Chart() : GUI_Element()
{
    
}

bool Chart::isClicked (std::shared_ptr<sf::RenderWindow> window)
{

    //check for a square in chartSquares

    //add an outline around it
    //make certain inputs the user can do to delete or drag a square to

    pixelPos = sf::Mouse::getPosition(*window);
    worldPos = window->mapPixelToCoords(pixelPos);
    for (auto beat : this->beatList)
    {
        rect = beat->getChartSquare()->getGlobalBounds();
        if(rect.contains(worldPos) && beat->isClicked(window))
        {
            if(beat->getChartSquare()->getFillColor() == sf::Color::Green) //switch off
            {       
                beat->getChartSquare()->setFillColor(sf::Color(252,172,172));
                return true;
            }

            else
            {   
                beat->getChartSquare()->setFillColor(sf::Color::Green); //switch on
                greenList.push_back(beat); //add to green selected
                return true;
            }
        }
    }
    //deselect
    for(auto green : this->greenList)
        green->getChartSquare()->setFillColor(sf::Color(252,172,172));
    this->greenList.clear();
    return false;        
}   
    


   


void Chart::addBeat(float timing, std::shared_ptr<sf::RectangleShape> rect, std::shared_ptr<sf::RectangleShape> chartBeat)
{
    std::shared_ptr<Beat> beat = std::make_shared<Beat>(timing, rect, chartBeat); 
    this->beatList.push_back(beat);
//     this->chartSquares.push_back(chartBeat);
//     this->beatSquares.push_back(rect); 
//     this->beatTimings.push_back(timing); 
}

void Chart::removeBeat(int x)
{
    std::vector<std::shared_ptr<Beat>>::iterator iter = this->beatList.begin() + (x-1);
    // std::vector<float>::iterator iter = this->beatTimings.begin() + (x-1);
    // std::vector<std::shared_ptr<sf::RectangleShape>>::iterator beatIter1 = this->beatSquares.begin() + (x-1);
    // std::vector<std::shared_ptr<sf::RectangleShape>>::iterator beatIter2 = this->chartSquares.begin() + (x-1);

    this->beatList.erase(iter);
    // this->beatTimings.erase(iter);
    // this->beatSquares.erase(beatIter1);
    // this->chartSquares.erase(beatIter2);
}


void Chart::draw(std::shared_ptr<sf::RenderWindow> window)
{
    for(auto beat : this->beatList)
        beat->draw(window);

    // for(auto beat : this->beatSquares)
    //     window->draw(*beat);
    
    // for(auto square : this->chartSquares)
    //     window->draw(*square);    

    // window->draw(this->chartShape);
}