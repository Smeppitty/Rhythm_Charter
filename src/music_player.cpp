#include "music_player.h"

Music_Player::Music_Player(std::string path)
{
    this->music.openFromFile(path);
}

Music_Player::Music_Player(std::vector<std::string> fileList)
{
    
}


void Music_Player::playTrack()
{
    this->music.setVolume(50);
    this->music.play();
    this->music.setLoop(true);
    this->isPlaying = true;
}

void Music_Player::changeTrack(std::string path)
{
    this->music.stop();
    this->isPlaying = false;
    this->music.openFromFile(path);
}

float Music_Player::getRatio()
{
    this->currentPos = this->music.getPlayingOffset().asSeconds();
    this->duration = this->music.getDuration().asSeconds();
    this->ratio = currentPos/duration;
    return this->ratio;     
}

std::string Music_Player::playTimeText()
{
    return this->playText;
}