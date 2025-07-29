#ifndef DEFENDCOMMAND_H
#define DEFENDCOMMAND_H

#include "Command.h"

class DefendCommand : public Command
{
public:
   DefendCommand();

   void Execute(Player& player) override;
};

#endif // !DEFENDCOMMAND_H