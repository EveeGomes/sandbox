#ifndef TREE_H
#define TREE_H

/*
* This class represents each actual tree. It's the the Context, or the Unique state.
*/

#include <memory>
#include <iostream>
#include "TreeType.h"

class Tree
{
   float _x{};
   float _y{};
   float _height{};
   std::shared_ptr<TreeType> _treeTypePtr{};

public:
   Tree() {};
   Tree(float x, float y, float height, std::shared_ptr<TreeType> treePtr)
      : _x{ x }, _y{ y }, _height{ height }, _treeTypePtr{ treePtr } {}

   // Print shared and unique data
   void Display() const;
};

#endif // !TREE_H