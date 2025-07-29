#ifndef ATTACKCOMMAND_H
#define ATTACKCOMMAND_H

#include "Command.h"
#include "Player.h"

class AttackCommand : public Command
{
public:
   AttackCommand();

   AttackCommand(Player* player);
   void Execute() override;

private:
   Player* m_Player{};
};

#endif // !ATTACKCOMMAND_H