#ifndef ATTACKCOMMAND_H
#define ATTACKCOMMAND_H

#include "Command.h"

class AttackCommand : public Command
{
public:
   AttackCommand();

   void Execute(Player& player) override;
};

#endif // !ATTACKCOMMAND_H