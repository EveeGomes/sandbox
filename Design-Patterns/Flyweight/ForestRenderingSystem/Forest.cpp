#include "Forest.h"

void Forest::PlantTree(float x, float y, float height, std::string name, std::string texture, std::string mesh)
{
   // Create a tree: use TreeFactory to get the shared TreeType and store it in the Tree's pointer
   Tree tree{x, y, height, _treeFactory.GetTreeType(name, texture, mesh)};

   // Then add to the vector of Trees
   _trees.push_back(tree);
}

void Forest::DisplayTrees() const
{
   for (const Tree& tree : _trees)
   {
      tree.Display();
   }
}