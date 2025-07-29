#ifndef JUMPCOMMAND_H
#define JUMPCOMMAND_H

/*
* Derived class of Command interface that holds a pointer to a Player object, and implements Execute virtual method. 
*/

#include "Command.h"

class JumpCommand : public Command
{
public:
   JumpCommand();

   void Execute(Player& player) override;

};

#endif // !JUMPCOMMAND_H