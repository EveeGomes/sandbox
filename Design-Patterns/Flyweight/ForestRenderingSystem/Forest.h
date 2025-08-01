#ifndef FOREST_H
#define FOREST_H

#include <vector>
#include <string>
#include <memory>
#include "Tree.h"
#include "TreeFactory.h"

class Forest
{
   std::vector<Tree> _trees{};
   TreeFactory _treeFactory{};

public:
   Forest() {}

   void PlantTree(float x, float y, float height, std::string name, std::string texture, std::string mesh);
   void DisplayTrees() const;
};

#endif // !FOREST_H