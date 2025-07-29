#ifndef JUMPCOMMAND_H
#define JUMPCOMMAND_H

/*
* Derived class of Command interface that holds a pointer to a Player object, and implements Execute virtual method. 
*/

#include "Command.h"
#include "Player.h"

class JumpCommand : public Command
{
public:
   JumpCommand();

   JumpCommand(Player* player);
   void Execute() override;

private:
   Player* m_Player{};
};

#endif // !JUMPCOMMAND_H