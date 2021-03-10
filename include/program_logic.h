#ifndef PROGRAM_LOGIC_H
#define PROGRAM_LOGIC_H

#include <SFML/Graphics.hpp>
#include <memory>

class Program_Logic
{
private:
    bool activeState = true;
    sf::Vector2f DEFAULT_WINDOW_SIZE = sf::Vector2f(1200.0f, 600.0f);

public:
    Program_Logic();

    bool getActiveState() { return activeState; }
    void setActiveState(bool b) { activeState = b; }

    sf::Vector2f getDefaultWindowSize() { return DEFAULT_WINDOW_SIZE; }
};
#endif 