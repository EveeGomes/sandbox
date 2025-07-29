#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <map>
#include "Command.h"

/*
* This class works as the Invoker.
*/

class InputHandler
{
public:
   InputHandler();

   void HandleInput(char input, Player& player);
   void BindCommand(char key, Command* command);

private:
   std::map<char, Command*> m_KeyCommands;
   Command* m_Jump{};
   Command* m_Attack{};
   Command* m_Defend{};
};

#endif // !INPUTHANDLER_H