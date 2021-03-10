#ifndef PROGRAM_VIEW_H
#define PROGRAM_VIEW_H

#include <SFML/Graphics.hpp>
#include "program_logic.h"
#include "gui_element.h"
#include "button.h"
#include "horizontal_scrollbar.h"

class Program_View
{
private:
    std::shared_ptr<Program_Logic> program_logic;
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1000,600,32), "XML Charter", sf::Style::Close);

    sf::Vector2f WINDOW_SIZE;

    std::vector<std::shared_ptr<GUI_Element>> gui_element_list;

public:
    Program_View(std::shared_ptr<Program_Logic> program_logic);

    void init();
    void pollInput();
    void draw();
    void update(const float& dt);
};
#endif 