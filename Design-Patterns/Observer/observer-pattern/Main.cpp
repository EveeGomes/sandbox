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
   Person() = default; // default constructor
   Person(int age) : m_age(age) {}
   
   int get_age() const
   {
      return m_age;
   }

   void set_age(int age)
   {
      // Now, Person has the ability to not only change the age but inform somebody about this change!

      // 1st check if the change has indeed been made (i.e. check for self assignment):
      if (m_age == age) return;

      // Now, before setting the age, we cache the old can_vote value in order to see if it has in fact changed or not.
      auto old_can_vote = get_can_vote();

      // set the value and notify:
      m_age = age;
      notify(*this, "age");

      // Compare the old value with the new value to determine if we'd need notification on can_vote as well.
      if (old_can_vote != get_can_vote())
      {
         // notify on this object and the name of the property (or in this case the "field" we have through the getter method get_can_vote)
         notify(*this, "can_vote");
      }
   }

   /** 
   * There's an issue with this paradigm which lies in dependencies. (Lesson 106)
   * Say we introduce a flag that tells whether a person can vote: get_can_vote(). If we want to manage the changes of that flag, we don't have
   *  a way of calling notify on it, because there is no setter (and so it becomes unclear where we should call notify).
   * The notify should be called in set_age since as we change the age, the flag also gets affected!
   */

   bool get_can_vote() const
   {
      return m_age >= 16;
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
      if (field_name == "can_vote") std::cout << std::boolalpha << source.get_can_vote();
      std::cout << ".\n";
   }
};

// However to use that observer the Observable class needs to support this paradigm 


int main(int arg, char* args[])
{
   Person p{};

   ConsolePersonObserver cpo;
   p.subscribe(cpo);

   p.set_age(15);
   p.set_age(16);


   return 0;
}