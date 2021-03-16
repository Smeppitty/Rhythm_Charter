#include "program_view.h"
#include <iostream>

Program_View::Program_View(std::shared_ptr<Program_Logic> program_logic)
{
    this->program_logic = program_logic;
    this->WINDOW_SIZE = this->program_logic->getDefaultWindowSize();
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_SIZE.x,WINDOW_SIZE.y,32), "XML Charter", sf::Style::Default);
    this->init();
}

void Program_View::init()
{   
    // this->music_player = std::make_shared<Music_Player>(or a list of strings);

    // this->music_player = std::make_shared<Music_Player>("../data/music/Milf_Inst.ogg");
    this->music_player = std::make_shared<Music_Player>("../data/music/Philly Nice - Friday Night Funkin' OST-HQ.ogg");
    // this->music_player = std::make_shared<Music_Player>("../data/music/Death Grips - Exmilitary - 3 - Spread Eagle Cross the Block.wav");

    this->font.loadFromFile("../data/fonts/orange kid.ttf");

    chart = std::make_shared<Chart>();
    horiz_scrollbar = std::make_shared<Horizontal_Scrollbar>("",sf::Color(211,211,211,32), sf::Vector2f(16.0f, WINDOW_SIZE.y-84.0f), sf::Vector2f(WINDOW_SIZE.x - 32.0f, WINDOW_SIZE.y * 0.02f));
    playTime = std::make_shared<Play_Time>(this->font, sf::Color::White, sf::Vector2f(0.0f,0.0f), 3, this->music_player);
    textfield = std::make_shared<Textfield>(sf::Color::White, sf::Vector2f(WINDOW_SIZE.x-128.0f, WINDOW_SIZE.y*0.01), sf::Vector2f(WINDOW_SIZE.x * 0.1f, WINDOW_SIZE.y * 0.05f));
 
    play_button = std::make_shared<Button>("",sf::Color::White, sf::Vector2f(WINDOW_SIZE.x/2.0f, WINDOW_SIZE.y-64.0f), sf::Vector2f(32.0f, 32.0f));
    stop_button = std::make_shared<Button>("",sf::Color::White, sf::Vector2f(WINDOW_SIZE.x/2.0f - 64.0f, WINDOW_SIZE.y-64.0f), sf::Vector2f(32.0f, 32.0f));
    chart_button = std::make_shared<Button>("",sf::Color::White, sf::Vector2f(WINDOW_SIZE.x/2.0f + 64.0f, WINDOW_SIZE.y-64.0f), sf::Vector2f(32.0f, 32.0f));

    gui_element_list.push_back(chart);
    gui_element_list.push_back(horiz_scrollbar);
    gui_element_list.push_back(textfield);

    gui_element_list.push_back(playTime); 
    gui_element_list.push_back(play_button);
    gui_element_list.push_back(stop_button);
    gui_element_list.push_back(chart_button);

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

                if((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)))
                    {
                        //reverse change

                        // this->chart->getTimings().pop_back();
                        // this->chart->getBeats().pop_back();
                    }

                switch(event.key.code)
                {
                    case sf::Keyboard::Q:
                    case sf::Keyboard::Escape:
                        this->program_logic->setActiveState(false);
                        break;
                    
                    case sf::Keyboard::P:
                        this->music_player->pauseTrack();
                        break;

                    case sf::Keyboard::Up:
                    case sf::Keyboard::W:
                        this->music_player->increaseVolume();
                        break;

                    case sf::Keyboard::Down:
                    case sf::Keyboard::S:
                        this->music_player->decreaseVolume();
                        break;

                    case sf::Keyboard::Left:
                    case sf::Keyboard::A:
                        this->music_player->decrementPos();
                        break;

                    case sf::Keyboard::Right:
                    case sf::Keyboard::D:
                        this->music_player->incrementPos();
                        break;

                    case sf::Keyboard::C:
                        this->chart_music();
                        break;

                    case sf::Event::TextEntered:
                        if(this->textfield->getOutlineColor() == sf::Color::Blue)
                        break;
                }

                case sf::Event::MouseButtonPressed:
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))                        
                        for(auto button : gui_element_list)
                            {
                                if(button->isClicked(this->window))
                                    if((button == this->play_button)) 
                                    {   
                                        if(this->music_player->getPlaying())
                                            this->music_player->pauseTrack();
                                        else
                                            this->music_player->playTrack();
                                    }

                                    else if(button == this->stop_button)
                                        this->music_player->stopTrack();
                                    
                                    else if(button == this->chart_button)
                                        this->chart_music();
                            }
            }
        }
    }

void Program_View::chart_music() //make a square and put it on the scrollbar, add to a vector of rectangleShapes
{
    std::shared_ptr<sf::RectangleShape> beat = std::make_shared<sf::RectangleShape>();
    // std::cout << "charted!" << std::endl;
    beat->setPosition(this->horiz_scrollbar->getThumbPos());
    beat->setOrigin(this->horiz_scrollbar->getThumbSize().x/4.0f, this->horiz_scrollbar->getThumbSize().y/4.0f);
    beat->setSize(sf::Vector2f(this->horiz_scrollbar->getThumbSize().x/2.0f,this->horiz_scrollbar->getThumbSize().y/2.0f));
    beat->setFillColor(sf::Color(252,172,172));

    std::shared_ptr<sf::RectangleShape> chartBeatImg = std::make_shared<sf::RectangleShape>();
    chartBeatImg->setPosition(this->horiz_scrollbar->getThumbPos().x, this->WINDOW_SIZE.y/2.0f);
    chartBeatImg->setSize(sf::Vector2f(this->horiz_scrollbar->getThumbSize().x/3.0f, this->horiz_scrollbar->getThumbSize().y/3.0f));
    chartBeatImg->setOrigin(sf::Vector2f(this->horiz_scrollbar->getThumbSize().x/2.0f, this->horiz_scrollbar->getThumbSize().y/2.0f));
    chartBeatImg->setFillColor(sf::Color(252,172,172));
    this->chart->addBeat(this->music_player->getPlayingPos(), beat, chartBeatImg);
}

void Program_View::track_music()
{
    this->horiz_scrollbar->autoScroll(this->window, this->music_player);
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
    track_music();
    pollInput();
    draw();
}