#ifndef IATTACKSTRATEGY_H
#define IATTACKSTRATEGY_H

class IAttackStrategy
{
public:
   virtual void Attack() const = 0;
   ~IAttackStrategy() = default;
};

#endif // !IATTACKSTRATEGY_H