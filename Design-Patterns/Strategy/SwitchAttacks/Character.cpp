#include "Character.h"

Character::Character() 
{
   m_attackStrategy = nullptr;
   m_name = "Dummy";
}

Character::Character(const std::string name)
{
   m_attackStrategy = nullptr;
   if (!name.empty())
   {
      m_name = name;
   }
   else
   {
      m_name = "Dummy";
   }
}

void Character::SetCharacterName(std::string name)
{
   m_attackStrategy = nullptr;
   if (!name.empty())
   {
      m_name = name;
   }
   else
   {
      m_name = "Dummy";
   }
}

void Character::GetPlayerName() const
{
   std::cout << m_name << "!\n" << std::endl;
}

void Character::SetAttackStrategy(IAttackStrategy* strategy)
{
   if (strategy)
   {
      m_attackStrategy = strategy;
   }
}

void Character::Attack() const
{
   if (m_attackStrategy)
   {
      m_attackStrategy->Attack();
   }
   else
   {
      std::cout << "No attack strategy set!" << std::endl;
   }
}