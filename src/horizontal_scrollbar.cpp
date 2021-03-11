#include "horizontal_scrollbar.h"

Horizontal_Scrollbar::Horizontal_Scrollbar(std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions) : GUI_Element(position)
{
    this->position = position;
    this->path = path;
    this->fillColor = fillColor;
    this->dimensions = dimensions;

    this->horizShape.setPosition(position);
    this->horizShape.setSize(dimensions);

    if(!this->horizTex.loadFromFile(path))
        this->horizShape.setFillColor(fillColor);
    else
        this->horizShape.setTexture(&horizTex);    

    /*
    / Slider in the scrollbar
    */
    this->thumbShape.setSize(sf::Vector2f(this->dimensions.x * 0.01f, this->dimensions.y));
    this->thumbShape.setPosition(this->position.x, this->position.y+this->thumbShape.getSize().y/2.0f);
    this->thumbShape.setOrigin(this->thumbShape.getSize().x / 2.0f, this->thumbShape.getSize().y / 2.0f);
}


bool Horizontal_Scrollbar::isClicked(std::shared_ptr<sf::RenderWindow> window)
{
    rect = this->thumbShape.getGlobalBounds();

    pixelPos = sf::Mouse::getPosition(*window);
    worldPos = window->mapPixelToCoords(pixelPos);

        if (rect.contains(worldPos)) 
            {   
                // this->thumbShape.setOutlineColor(sf::Color::Blue);
                return true;
            }
        // this->thumbShape.setOutlineColor(sf::Color::Transparent);
        return false; 
}


void Horizontal_Scrollbar::scrub(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Music_Player> music_player)
{
    sf::Event event;
    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left )
            {
                startingPos.x = event.mouseButton.x;
                startingPos.y = event.mouseButton.y;
            }

            if( event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left) )
            {
                this->currentPos.x = event.mouseMove.x - startingPos.x;
                this->currentPos.y = event.mouseMove.y - startingPos.y;
                this->thumbShape.setPosition( startingPos.x , startingPos.y );
            }
}


void Horizontal_Scrollbar::autoScroll(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Music_Player> music_player)
{
    this->thumbShape.setPosition(this->horizShape.getSize().x * music_player->getRatio() + this->thumbShape.getSize().x, this->thumbShape.getPosition().y);
}


void Horizontal_Scrollbar::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(this->horizShape);
    window->draw(this->thumbShape);
}