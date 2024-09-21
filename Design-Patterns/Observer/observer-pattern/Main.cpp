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


/** 
* Implementing a different interface using Boost.Signals2, which is one the Boost libraries specifically designed to implement the Observer pattern
*  via the use of SIGNALS and SLOTS. Signals are basically used as variables whose value we can subscribe to, and when fired the slots (subscribers)
*  get notifications.
*/
// Build an Observable specifically for boots
template <typename T> struct Observable2
{
   // Create a signal and specify the signature of the function that's gonna be invoked, which in our case is a ref to the obj that's been changed
   //  and the name of the field
   boost::signals2::signal<void(T& objChanged, const std::string& fieldName)> field_changed;
};

// Create another class Person2 that implements the Observable2
class Person2 : public Observable2<Person2>
{
   /** 
   * This class will reconstruct the age in a similar fashion, but we'll use something that's already made (use Signals2).
   */
   // Fields
   int m_age;

public:
   /** Getter and Setters */
   int get_age() const { return m_age; }
   void set_age(int age)
   {
      if (this->m_age == age) return;

      // Change/Set m_age (a field) and notify all the subscribers (slots) via the signal we've created!
      this->m_age = age;
      // invoke on the signal so it notify all the slots
      field_changed(*this, "age"); // specify the obj and the field name
   }
};

int main(int arg, char* args[])
{
   // Put Observer and Observable together by connecting them using the subscribe function!

   Person person{ 10 };
   ConsolePersonObserver cpo;

   // Connect them:
   person.subscribe(cpo);

   // Now we can change the ages and get notification about it!
   person.set_age(11);
   person.set_age(12);

   // Unsubscribe an observer and stop getting notification
   person.unsubscribe(cpo);
   person.set_age(13);


   return 0;
}