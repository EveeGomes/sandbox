#include "Tree.h"

void Tree::Display() const
{
   std::cout << "=== Tree Instance ===" << std::endl;
   _treeTypePtr->DisplaySharedInfo();
   std::cout << "Position: (" << _x << "," << _y << ")" << std::endl;
   std::cout << "Height: " << _height << std::endl;
   std::cout << "=====================\n" << std::endl;
}