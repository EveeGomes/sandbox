#include "JumpCommand.h"

JumpCommand::JumpCommand() {}

void JumpCommand::Execute(Player& player)
{
   player.Jump();
}
