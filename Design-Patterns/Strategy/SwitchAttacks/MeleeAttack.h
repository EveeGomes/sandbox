#ifndef MELEEATTACK_H
#define MELEEATTACK_H

#include <iostream>
#include "IAttackStrategy.h"

class MeleeAttack : public IAttackStrategy
{
   void Attack() const override;
};


#endif // !MELEEATTACK_H