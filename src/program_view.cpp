#include "program_view.h"

Program_View::Program_View(std::shared_ptr<Program_Logic> program_logic)
{
    this->program_logic = program_logic;
    this->WINDOW_SIZE = this->program_logic->getDefaultWindowSize();
    this->init();
}

void Program_View::init()
{
    play_button = std::make_shared<Button>("",sf::Color::White, sf::Vector2f(WINDOW_SIZE.x/2.0f, WINDOW_SIZE.y-64.0f), sf::Vector2f(32.0f, 32.0f));
    stop_button = std::make_shared<Button>("",sf::Color::White, sf::Vector2f(WINDOW_SIZE.x/2.0f - 64.0f, WINDOW_SIZE.y-64.0f), sf::Vector2f(32.0f, 32.0f));
    horiz_scrollbar = std::make_shared<Horizontal_Scrollbar>("",sf::Color(211,211,211,32), sf::Vector2f(16.0f, WINDOW_SIZE.y-84.0f), sf::Vector2f(WINDOW_SIZE.x - 32.0f, WINDOW_SIZE.y * 0.01f));
    
    button_list.push_back(play_button);
    button_list.push_back(stop_button);

    gui_element_list.push_back(play_button);
    gui_element_list.push_back(stop_button);
    gui_element_list.push_back(horiz_scrollbar);
}

void Program_View::pollInput()
{
    // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {   
            switch(event.type)
            {
                case sf::Event::Closed:
                    this->program_logic->setActiveState(false);
                    break;
                case sf::Event::Resized:
                    WINDOW_SIZE.x = event.size.width;
                    WINDOW_SIZE.y = event.size.height;
                    break;                

                case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Q:
                    case sf::Keyboard::Escape:
                        this->program_logic->setActiveState(false);
                        break;                
                }
            }
        }
}


void Program_View::draw()
{
    window->clear();
    
    for(auto gui_element : this->gui_element_list)
        gui_element->draw(this->window);    

    window->display();
}

void Program_View::update(const float& dt)
{
    draw();
    pollInput();
}

void Program_View::music(std::string path)
{
    Music_Player music_player(path);
}