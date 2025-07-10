#ifndef RANGEDATTACK_H
#define RANGEDATTACK_H

#include <iostream>
#include "IAttackStrategy.h"

class RangedAttack : public IAttackStrategy
{
   void Attack() const override;
};

#endif // !RANGEDATTACK_H