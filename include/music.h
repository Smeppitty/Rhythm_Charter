#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.hpp>
#include <string>

class Music
{
private:
    std::string path;
public:
    Music(std::string path);
    ~Music();
};
#endif