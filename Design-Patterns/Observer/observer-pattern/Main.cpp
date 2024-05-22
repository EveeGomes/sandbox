// From Udemy Design Patterns in Modern C++

// Observer: the thing that monitors something
// Observable: the component is the one to be obeserved

#include <iostream>
#include "Observer.h"

class Person // observable
{
   int m_age;
public:
   Person(int age) { m_age = age; }
   
   int get_age() const
   {
      return m_age;
   }

   void set_age(int age)
   {
      m_age = age; // in the video he uses Person::m_age = age;
   }
};

// Make a simple observer that prints something to the console. 
// It'll implement an Observer of Person interface
struct ConsolePersonObserver : public Observer<Person>
{
private:
   // implement the field_changed virtual method
   void field_changed(Person& source, const std::string& field_name) override
   {
      std::cout << "Person's " << field_name << " has changed to: ";
      if (field_name == "age") std::cout << source.get_age();
      std::cout << ".\n";
   }
};

// However to use that observer the Observable class needs to support this paradigm 


int main(int arg, char* args[])
{


   return 0;
}