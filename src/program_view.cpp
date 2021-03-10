#include "program_view.h"
#include <iostream>

Program_View::Program_View(std::shared_ptr<Program_Logic> program_logic)
{
    this->program_logic = program_logic;
    this->WINDOW_SIZE = this->program_logic->getDefaultWindowSize();
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_SIZE.x,WINDOW_SIZE.y,32), "XML Charter", sf::Style::Close);
    this->init();
}

void Program_View::init()
{   
    this->music = std::make_shared<sf::Music>();
    // this->music_player = std::make_shared<Music_Player>(this->music,"../data/music/Milf_Inst.ogg");

    play_button = std::make_shared<Button>("",sf::Color::White, sf::Vector2f(WINDOW_SIZE.x/2.0f, WINDOW_SIZE.y-64.0f), sf::Vector2f(32.0f, 32.0f));
    stop_button = std::make_shared<Button>("",sf::Color::White, sf::Vector2f(WINDOW_SIZE.x/2.0f - 64.0f, WINDOW_SIZE.y-64.0f), sf::Vector2f(32.0f, 32.0f));
    horiz_scrollbar = std::make_shared<Horizontal_Scrollbar>("",sf::Color(211,211,211,32), sf::Vector2f(16.0f, WINDOW_SIZE.y-84.0f), sf::Vector2f(WINDOW_SIZE.x - 32.0f, WINDOW_SIZE.y * 0.02f));
    textfield = std::make_shared<Textfield>(sf::Color::White, sf::Vector2f(WINDOW_SIZE.x-64.0f, WINDOW_SIZE.y/2), sf::Vector2f(WINDOW_SIZE.x/3.0f, WINDOW_SIZE.y/5.0f));
    
    gui_element_list.push_back(textfield);
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
                case sf::Event::MouseButtonPressed:
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        for(auto button : gui_element_list)
                            {
                                if((button == this->play_button) && button->isClicked(this->window))
                                {   
                                    // if(this->music_player->getPlaying())
                                    //     if(this->music_player->pauseTrack())
                                    // else
                                    //     // this->music_player->playTrack();

                                    std::cout<< "play music" << std::endl;
                                }
                            }
                // }
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