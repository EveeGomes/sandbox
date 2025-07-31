#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include <map>
#include "TreeType.h"

class TreeFactory
{
   std::map<std::string, TreeType*> _treeTypeInstances;

public:
   TreeFactory() {};

   // Returns a TreeType if there's any, otherwise create, store and return one
   TreeType* GetTreeType(std::string name, std::string texture, std::string mesh);
};

#endif // !TREEFACTORY_H