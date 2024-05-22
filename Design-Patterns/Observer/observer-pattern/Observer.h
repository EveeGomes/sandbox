#pragma once

#include <string>

template <typename T>
class Observer
{
   // the purpose of this obsever is to track changes in a particular field of a particular T type

   // this method will check who's field has changed and what's the name of the field
   virtual void field_changed(T& source, const std::string& field_name) = 0;
};

