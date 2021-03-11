#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <SFML/Audio.hpp>
#include <memory>
#include <string>
#include <iostream>

class Music_Player
{
private:
    sf::Music music;

    std::string playText;
    float currentPos;
    float duration;
    float ratio;

    bool isPlaying = false;

public:
    Music_Player(std::string path);

    void increaseVolume() { this->music.setVolume( this->music.getVolume() + 5 ); }
    void decreaseVolume() { this->music.setVolume( this->music.getVolume() - 5 ); }

    void incrementPos() { this->music.setPlayingOffset( this->music.getPlayingOffset() + sf::seconds(5.0f)); }
    void decrementPos() { this->music.setPlayingOffset( sf::Time(this->music.getPlayingOffset() - sf::seconds(5.0f))); }

    void setMusicPos(float pos) { this->music.setPlayingOffset(sf::seconds(pos)); }

    void playTrack();
    void stopTrack() { this->music.stop(); this->isPlaying = false; }
    void pauseTrack() { this->music.pause(); this->isPlaying = false;}

    void changeTrack(std::string path);

    bool getPlaying() { return this->isPlaying; }
    void setPlaying(bool p){ this->isPlaying = p; }

    float getRatio();

    std::string playTimeText();
};
#endif