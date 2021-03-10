#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <SFML/Audio.hpp>
#include <memory>
#include <string>

class Music_Player
{
private:
    std::shared_ptr<sf::Music> music;

    bool isPlaying = false;
public:
    Music_Player(std::shared_ptr<sf::Music> music, std::string path);

    void playTrack();
    void stopTrack() { this->music->stop(); }
    void pauseTrack() { this->music->pause(); }

    void changeTrack(std::string path);

    bool getPlaying() { return isPlaying; }
    void setPlaying(bool p){ this->isPlaying = p; }
    
    
        
};
#endif