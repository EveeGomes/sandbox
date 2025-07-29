#include "JumpCommand.h"

JumpCommand::JumpCommand() {}

JumpCommand::JumpCommand(Player* player)
{
   if (player)
   {
      m_Player = player;
   }
}

void JumpCommand::Execute()
{
   if (m_Player)
   {
      m_Player->Jump();
   }
}
