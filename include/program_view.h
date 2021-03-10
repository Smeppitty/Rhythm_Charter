#ifndef PROGRAM_VIEW_H
#define PROGRAM_VIEW_H

#include <SFML/Graphics.hpp>
#include "program_logic.h"

class Program_View
{
private:
    std::shared_ptr<Program_Logic> program_logic;
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1600,900,32), "Pong", sf::Style::Titlebar || sf::Style::Close);

public:
    Program_View(std::shared_ptr<Program_Logic> program_logic);
    ~Program_View();    

    void update(const float& dt);
    void draw();
};
#endif 