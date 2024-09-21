// From Udemy Design Patterns in Modern C++

// Observer: the thing that monitors something
// Observable: the component is the one to be obeserved

#include <iostream>
#include "Observer.h"
#include "Observable.h"

// Boost libraries
#include "boost/signals2.hpp"

class Person : public Observable<Person> // Person class implements an Observable of Person
{
   int m_age;
public:
   Person(int age) : m_age(age) {}
   
   int get_age() const
   {
      return m_age;
   }

   void set_age(int age)
   {
      // Now, Person has the ability to not only change the age but inform somebody about this change!

      // 1st check if the change has indeed made:
      if (m_age == age) return;

      // set the value and notify:
      m_age = age;
      notify(*this, "age");
   }

   /** 
   * There's an issue with this paradigm which lies in dependencies. (Lesson 106)
   * Say we introduce a flag that tells whether a person can vote: get_can_vote(). If we want to manage the changes of that flag, we don't have
   *  a way of calling notify on it, because there is no setter (and so it becomes unclear where we should call notify).
   * The notify should be called in set_age since as we change the age, the flag also get affected!
   * 
   */
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