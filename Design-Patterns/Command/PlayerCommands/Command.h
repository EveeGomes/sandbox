#ifndef COMMAND_H
#define COMMAND_H

/*
* Command interface
*/
#include "Player.h"

class Command
{
public:
   virtual ~Command() = default;
   virtual void Execute(Player& player) = 0;
};

#endif // !COMMAND_H