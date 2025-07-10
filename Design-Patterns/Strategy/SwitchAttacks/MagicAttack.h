#ifndef MAGICATTACK_H
#define MAGICATTACK_H

#include <iostream>
#include "IAttackStrategy.h"

class MagicAttack : public IAttackStrategy
{
   void Attack() const override;
};

#endif // !MAGICATTACK_H