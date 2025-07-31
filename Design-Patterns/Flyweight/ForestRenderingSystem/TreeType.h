#ifndef TREETYPE_H
#define TREETYPE_H

/*
* This class holds the intrisic data of trees, ie data that's common to every tree so it can be shared.
*/

#include <string>


class TreeType
{
   std::string _name{};
   std::string _texture{};
   std::string _mesh{};

public:
   TreeType(std::string name, std::string texture, std::string mesh)
      : _name{ name }, _texture{ texture }, _mesh{ mesh } {}

   void DisplaySharedInfo() const;
};

#endif // !TREETYPE_H