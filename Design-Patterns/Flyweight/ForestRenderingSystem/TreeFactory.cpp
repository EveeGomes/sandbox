#include "TreeFactory.h"

TreeType* TreeFactory::GetTreeType(std::string name, std::string texture, std::string mesh)
{
   auto treeIterator = _treeTypeInstances.find(name);

   if (treeIterator == _treeTypeInstances.end())
   {
      // it doesn't exist, so create one, store in the map and return it
      _treeTypeInstances[name] = new TreeType{ name, texture, mesh };
   }
   
   return _treeTypeInstances[name];
}