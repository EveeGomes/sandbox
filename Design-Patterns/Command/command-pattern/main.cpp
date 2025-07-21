#include <iostream>
#include <vector>

/*
* The command pattern allows for decoupling the command from the real action.
* There should be a separation of concerns where there's a command class, serving as a base class which is an interface with a single pure virtual method,
*  which forces any derived class to implement it. Normally it's called "Execute()".
* In a derived class, which is a concrete command, there will be a reference to a receiver as well as any data/info that's needed to implement the Execute
*  method. In that implementation we'll use the receiver reference to call a method responsible for the action that it'll be performed by this receiver.
*  So in this scenario, the command per se has no clue how the action really works, it only issues the command through the receiver reference.
* Then, we can have a handler (or invoker) to call the Execute() method according to some input, for example. Say we're talking about implementing an input
*  handler, where buttons are bound to certain commands, so when a player presses space it will issue the JumpCommand which will tell the character to perform
*  its jump method. That will happen as:
*  Command* space = JumpCommand(&player);
*  space->Execute();
*/

// Receiver
struct BankAccount
{
   int balance{ 0 };
   int overdraftLimit{ -500 };

   void deposit(int amount)
   {
      balance += amount;
      std::cout   << "Deposited " << amount 
                  << ", balance is now " << balance << std::endl;
   }

   void withdraw(int amount)
   {
      if (balance - amount >= overdraftLimit)
      {
         balance -= amount;
         std::cout   << "Withdrew " << amount
                     << ", balance is now " << balance << std::endl;
      }
   }

   friend std::ostream& operator<<(std::ostream& os, const BankAccount& account)
   {
      os << "Balance: " << account.balance;
      return os;
   }
};

/*
* Now, have a way of manipulating the bank account as well as recording the fact that it was manipulated.
* For it we'll have objects, that we'll call commands, for performing those operations.
*/

// Command interface
struct Command
{
   virtual void call() = 0;
};

// Concrete command
struct BankAccountCommand : Command
{
   // Have a reference to the bank account we'll operate on
   BankAccount& account;
   // Define the kinds of actions we want to perform
   enum Action {deposit, withdraw} action;
   int amount;

   // Constructor to initialize all fields
   BankAccountCommand(BankAccount& account, Action action, int amount)
      : account(account), action(action), amount(amount) {}

   // Implement the call function: we need to know which action has been requested
   void call() override
   {
      switch (action)
      {
      case deposit:
         account.deposit(amount);
         break;
      case withdraw:
         account.withdraw(amount);
         break;
      }
   }
};

int main()
{
   /*
   * Using the command:
   * Have a bank account and then a command or series of commands
   */
   BankAccount ba;
   std::vector<BankAccountCommand> commands
   {
      BankAccountCommand{ba, BankAccountCommand::deposit, 100},
      BankAccountCommand{ba, BankAccountCommand::withdraw, 200}
   };
   std::cout << ba << std::endl;

   /*
   * Invoker
   * Process the commands: each command calls call() and perform what the action they have reference of
   */
   for (auto& cmd : commands)
   {
      cmd.call();
   }
   std::cout << ba << std::endl;
    
   return 0;
}