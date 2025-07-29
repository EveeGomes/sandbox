#include "InputHandler.h"

InputHandler::InputHandler() {}

void InputHandler::HandleInput(char input, Player& player)
{
   auto KeyIterator = m_KeyCommands.find(input);
   if (KeyIterator != m_KeyCommands.end() && KeyIterator->second)
   {
      KeyIterator->second->Execute(player);
   }
}

void InputHandler::BindCommand(char key, Command* command)
{
   if (command && key != ' ')
   {
      m_KeyCommands[key] = command;
   }
}