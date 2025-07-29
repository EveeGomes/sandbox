#include "AttackCommand.h"

AttackCommand::AttackCommand() {}

AttackCommand::AttackCommand(Player* player)
{
   if (player)
   {
      m_Player = player;
   }
}

void AttackCommand::Execute()
{
   if (m_Player)
   {
      m_Player->Attack();
   }
}
