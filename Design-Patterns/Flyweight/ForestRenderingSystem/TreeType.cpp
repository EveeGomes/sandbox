#include "TreeType.h"

void TreeType::DisplaySharedInfo() const
{
   std::cout << "Tree name: " << _name << std::endl;
   std::cout << "Rendering texture: " << _texture << std::endl;
   std::cout << "Mesh: " << _mesh << std::endl;
}
