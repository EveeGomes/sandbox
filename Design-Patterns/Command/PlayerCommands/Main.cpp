#include "JumpCommand.h"
#include "AttackCommand.h"
#include "DefendCommand.h"
#include "InputHandler.h"

int main()
{
   char input{};

   Player player;
   JumpCommand jump;
   AttackCommand attack;
   DefendCommand defend;
   InputHandler inputHandler;

   inputHandler.BindCommand('j', &jump);
   inputHandler.BindCommand('a', &attack);
   inputHandler.BindCommand('d', &defend);

   while (input != 'q')
   {
      std::cout << "Press\n j to jump\n a to attack\n d to defend\n\nPress q if you want to quit.\n>> ";
      std::cin >> input;

      inputHandler.HandleInput(input, player);
   }

   return 0;
}