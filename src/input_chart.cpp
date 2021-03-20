#include "input_chart.h"

Input_Chart::Input_Chart(/* args */)
{
}

void Input_Chart::draw(std::shared_ptr<sf::RenderWindow> window)
{   
    for(auto input : this->inputList)
        window->draw(*input);
}
