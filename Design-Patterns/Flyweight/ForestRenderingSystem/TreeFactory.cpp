#include "TreeFactory.h"

TreeType* TreeFactory::GetTreeType(std::string name, std::string texture, std::string mesh)
{
   std::map<std::string, TreeType*>::iterator treeIterator;
   treeIterator = _treeTypeInstances.find(name);

   //if (treeIterator != _treeTypeInstances.end())
   //{
   //   // it already exists, return it
   //   return treeIterator->second;
   //}
   //else
   //{
   //   // create one, store in the map and return it
   //}

   if (treeIterator == _treeTypeInstances.end())
   {
      // it doesn't exist, so create one, store in the map and return it
      TreeType* newTreePtr = new TreeType{ name, texture, mesh };
      _treeTypeInstances.insert(std::pair<std::string, TreeType*>(name, newTreePtr));
      treeIterator = _treeTypeInstances.find(name);

      return treeIterator->second;
   }
   
   return treeIterator->second;
}
