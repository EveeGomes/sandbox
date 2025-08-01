#include "TreeType.h"

int TreeType::_treeTypeCount = 0;

void TreeType::DisplaySharedInfo() const
{
   std::cout << "Tree name: " << _name << std::endl;
   std::cout << "Rendering texture: " << _texture << std::endl;
   std::cout << "Mesh: " << _mesh << std::endl;
}

void TreeType::PrintTreeTypeCounter()
{
   std::cout << "Number of unique TreeType instances: " << _treeTypeCount << std::endl;
}