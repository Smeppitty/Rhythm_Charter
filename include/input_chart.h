#ifndef INPUT_CHART_H
#define INPUT_CHART_H

#include "gui_element.h"

class Input_Chart : public GUI_Element
{
private:
    std::vector<std::shared_ptr<sf::RectangleShape>> inputList;
public:
    Input_Chart();
    void addInput();
    void delInput();
    void moveInput();

    void importInput();
    void exportInput();

    void draw(std::shared_ptr<sf::RenderWindow> window);
};

#endif