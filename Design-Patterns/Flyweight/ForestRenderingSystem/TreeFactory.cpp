#include "TreeFactory.h"

std::shared_ptr<TreeType> TreeFactory::GetTreeType(std::string name, std::string texture, std::string mesh)
{
   auto treeIterator = _treeTypeInstances.find(name);

   if (treeIterator == _treeTypeInstances.end())
   {
      // it doesn't exist, so create one, store in the map and return it
      _treeTypeInstances[name] = std::make_shared<TreeType>(name, texture, mesh );
   }
   
   return _treeTypeInstances[name];
}