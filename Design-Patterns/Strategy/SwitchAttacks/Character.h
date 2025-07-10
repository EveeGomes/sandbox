#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "IAttackStrategy.h"

class Character
{
private:
   IAttackStrategy* m_attackStrategy;
   std::string m_name;

public:
   Character();
   Character(std::string name);
   void SetCharacterName(std::string name);
   void GetPlayerName() const;
   void SetAttackStrategy(IAttackStrategy* strategy);
   void Attack() const;
};

#endif // !CHARACTER_H