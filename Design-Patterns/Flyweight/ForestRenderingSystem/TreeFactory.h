#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include <map>
#include <memory>
#include "TreeType.h"

class TreeFactory
{
   std::map<std::string, std::shared_ptr<TreeType>> _treeTypeInstances;

public:
   TreeFactory() {};

   // Returns a TreeType if there's any, otherwise create, store and return one
   std::shared_ptr<TreeType> GetTreeType(std::string name, std::string texture, std::string mesh);
};

#endif // !TREEFACTORY_H