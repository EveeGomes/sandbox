#include "Command.h"
#include "JumpCommand.h"
#include "AttackCommand.h"
#include "DefendCommand.h"
#include "InputHandler.h"
#include "Player.h"

int main()
{
   Player player;
   JumpCommand jump(&player);
   AttackCommand attack(&player);
   DefendCommand defend(&player);

   InputHandler inputHandler;
   inputHandler.BindCommand('j', &jump);
   inputHandler.BindCommand('a', &attack);
   inputHandler.BindCommand('d', &defend);

   char input{};

   while (input != 'q')
   {
      std::cout << "Press\n j to jump\n a to attack\n d to defend\n\nPress q if you want to quit.\n>> ";
      std::cin >> input;

      inputHandler.HandleInput(input);
   }

   return 0;
}