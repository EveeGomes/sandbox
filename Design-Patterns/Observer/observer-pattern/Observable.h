#pragma once

// This is the interface that an observable object type should implement

// What kinds of operations are needed?
// In this case we need a list of all subscribers aka observers which are attatched to this observable!

#include <string>
#include <vector>

/** Forward declaration */
template<typename> struct Observer;

template <typename T>
struct Observable
{
   std::vector<Observer<T>*> observers; // Subscribers that want to be notified when something has changed in this observable!
public:
   // public members that will manipulate the observable

   // Notify all obvservers that something has changed to the observable
   void notify(T& source, const std::string& field_name)
   {
      for (auto observer : observers) // for each observer
        observer->field_changed(source, field_name); // fire a notification
   }

   // Subscribe an observer
   void subscribe(Observer<T>& observer) // making the interface more usable
   {
      observers.push_back(&observer); // the address of observer because we're sending to the vector of pointers to type Observer<T> objects!!!!
   }

   void unsubscribe(Observer<T>& observer)
   {
      // use the erase remove idiom:
      observers.erase(
         remove(observers.begin(), observers.end(), &observer), observers.end()
      );
   }
};

