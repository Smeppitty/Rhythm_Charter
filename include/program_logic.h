#ifndef PROGRAM_LOGIC_H
#define PROGRAM_LOGIC_H

#include <memory>

class Program_Logic
{
private:
    bool activeState = true;
public:
    Program_Logic();
    ~Program_Logic();

    bool getActiveState() { return activeState;};
};
#endif 