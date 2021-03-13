#include <SFML/Graphics.hpp>
#include "program_view.h"

int main(int argc, char** argv)
{
  std::shared_ptr<Program_Logic> program_logic = std::make_shared<Program_Logic>();
  std::shared_ptr<Program_View> program_view = std::make_shared<Program_View>(program_logic);

  // start main loop
  sf::Clock dtClock;  
  float dt = 0.0f;

  while(program_logic->getActiveState())
  {
      dt = dtClock.restart().asSeconds();
      program_view->update(dt);
  }
  // Done.
  return 0;
}