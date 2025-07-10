#include "Character.h"
#include "MeleeAttack.h"
#include "RangedAttack.h"
#include "MagicAttack.h"

int main()
{
   MeleeAttack melee;
   RangedAttack ranged;
   MagicAttack magic;
   int input = -1;
   Character Player;

   /*Character Player;*/
   std::string playerName = "";
   std::cout << "Please tell me your name: ";
   std::cin >> playerName;

   //if (!playerName.empty())
   //{
   //   Character Player(playerName);
   //}
   //else
   //{
   //   Character Player;
   //}

   if (!playerName.empty())
   {
      Player.SetCharacterName(playerName);
   }
   else
   {
      Player.SetCharacterName("");
   }
   std::cout << "Hello ";
   Player.GetPlayerName();
   

   while (input != 0)
   {
      std::cout << "Choose attack mode: \n1) Melee\n2) Ranged\n3) Magic\n0) Exit\n";
      std::cout << ">> ";
      std::cin >> input;

      switch (input)
      {
      case 1:
         Player.SetAttackStrategy(&melee);
         Player.Attack();
         break;
      case 2:
         Player.SetAttackStrategy(&ranged);
         Player.Attack();
         break;
      case 3:
         Player.SetAttackStrategy(&magic);
         Player.Attack();
         break;
      case 0:
         std::cout << "\nExit attack mode. Bye bye." << std::endl;
         return 0;
      default:
         std::cout << "Invalid input.\n";
      }
      std::cout << std::endl;
   }

   return 0;
}