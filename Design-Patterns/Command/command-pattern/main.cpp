#include <iostream>
#include <vector>

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

struct Command
{
   virtual void call() = 0;
};

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
   * Process the commands: each command calls call() and perform what the action they have reference of
   */
   for (auto& cmd : commands)
   {
      cmd.call();
   }
   std::cout << ba << std::endl;
    
   return 0;
}