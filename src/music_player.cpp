#include "music_player.h"

Music_Player::Music_Player(std::string path)
{
    this->path = path;
    this->music.openFromFile(path);
}

void Music_Player::playTrack()
{
    this->music.setVolume(50);
    this->music.play();
}

void Music_Player::changeTrack(std::string path)
{
    this->music.stop();
    this->music.openFromFile(path);
}