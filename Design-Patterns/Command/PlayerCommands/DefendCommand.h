#ifndef DEFENDCOMMAND_H
#define DEFENDCOMMAND_H

#include "Command.h"
#include "Player.h"

class DefendCommand : public Command
{
public:
   DefendCommand();

   DefendCommand(Player* player);
   void Execute() override;

private:
   Player* m_Player{};
};


#endif // !DEFENDCOMMAND_H