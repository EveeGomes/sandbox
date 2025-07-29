#include "DefendCommand.h"

DefendCommand::DefendCommand() {}

DefendCommand::DefendCommand(Player* player)
{
   if (player)
   {
      m_Player = player;
   }
}

void DefendCommand::Execute()
{
   if (m_Player)
   {
      m_Player->Defend();
   }
}
