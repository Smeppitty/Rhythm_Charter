#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <SFML/Audio.hpp>
#include <string>

class Music_Player
{
private:
    std::string path;
    sf::Music music;
public:
    Music_Player(std::string path);

    void playTrack();
    void stopTrack() { this->music.stop(); }
    void pauseTrack() { this->music.pause(); }

    void changeTrack(std::string path);
    
    
        
};
#endif