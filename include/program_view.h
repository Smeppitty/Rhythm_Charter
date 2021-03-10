#ifndef PROGRAM_VIEW_H
#define PROGRAM_VIEW_H

#include <SFML/Graphics.hpp>
#include "program_logic.h"
#include "gui_element.h"
#include "button.h"
#include "horizontal_scrollbar.h"
#include "music_player.h"

class Program_View
{
private:
    std::shared_ptr<Program_Logic> program_logic;
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1000,600,32), "XML Charter", sf::Style::Close);
    sf::Vector2f WINDOW_SIZE;

    std::shared_ptr<Button> play_button;
    std::shared_ptr<Button> stop_button;
    std::shared_ptr<Horizontal_Scrollbar> horiz_scrollbar;

    std::shared_ptr<Music_Player> music_player;
    
    std::vector<std::shared_ptr<GUI_Element>> button_list;
    std::vector<std::shared_ptr<GUI_Element>> gui_element_list;

    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;

public:
    Program_View(std::shared_ptr<Program_Logic> program_logic);

    void init();
    void pollInput();
    void draw();
    void music(std::string path);
    void update(const float& dt);
};
#endif 