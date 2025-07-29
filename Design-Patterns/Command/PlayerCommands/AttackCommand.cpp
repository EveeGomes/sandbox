#include "AttackCommand.h"

AttackCommand::AttackCommand() {}

void AttackCommand::Execute(Player& player)
{
   player.Attack();
}
