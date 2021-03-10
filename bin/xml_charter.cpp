#include <SFML/Graphics.hpp>

#include "program_logic.h"
#include "program_view.h"

int main(int argc, char** argv)
{
  std::shared_ptr<Program_Logic> program_logic = std::make_shared<Program_Logic>();
  std::shared_ptr<Program_View> program_view = std::make_shared<Program_View>(program_logic);

  // start main loop
  sf::Clock dtClock;  
  float dt = 0.0f;
  std::shared_ptr<sf::Music> music;
  // std::shared_ptr<Music_Player> music_player = std::make_shared<Music_Player>(music,"../data/music/Milf_Inst.ogg");
  while(program_logic->getActiveState())
  {
      dt = dtClock.restart().asSeconds();
      // music_player->playTrack();
      program_view->update(dt);
  }
  // Done.
  return 0;
}