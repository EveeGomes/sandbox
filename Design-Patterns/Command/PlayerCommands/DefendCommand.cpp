#include "DefendCommand.h"

DefendCommand::DefendCommand() {}

void DefendCommand::Execute(Player& player)
{
   player.Defend();
}
