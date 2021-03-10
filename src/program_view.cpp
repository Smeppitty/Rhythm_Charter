#include "program_view.h"

Program_View::Program_View(std::shared_ptr<Program_Logic> program_logic)
{
    this->program_logic = program_logic;
}

void Program_View::update(const float& dt)
{

}

void Program_View::draw()
{
    window->clear();

    window->display();
}

Program_View::~Program_View(){}