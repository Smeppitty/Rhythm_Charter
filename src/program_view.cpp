#include "program_view.h"

Program_View::Program_View(std::shared_ptr<Program_Logic> program_logic)
{
    this->program_logic = program_logic;
}

void Program_View::init()
{
    std::shared_ptr<Button> play_button = std::make_shared<Button>("",sf::Color::White, sf::Vector2f(WINDOW_SIZE.x/2.0f, WINDOW_SIZE.y-16.0f), sf::Vector2f(16.0f, 16.0f));
    std::shared_ptr<Button> play_button = std::make_shared<Button>("",sf::Color::White, sf::Vector2f(WINDOW_SIZE.x/2.0f, WINDOW_SIZE.y-16.0f), sf::Vector2f(16.0f, 16.0f));


    gui_element_list.push_back(play_button);
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