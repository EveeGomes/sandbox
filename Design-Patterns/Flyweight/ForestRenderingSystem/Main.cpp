#include "Forest.h"
#include "TreeType.h"

const int NUMBEROFTREES = 10;

int main()
{
   Forest forest{};

   // Plant NUMBEROFTREES trees
   for (int x = 0, y = 1; x < NUMBEROFTREES; ++x, ++y)
   {
      if (x >= NUMBEROFTREES / 2)
      {
         forest.PlantTree(x + 1, y + 1, y + 10.f, "Pine", "texture1", "mesh1");
      }
      else
      {
         forest.PlantTree(x + 1, y + 1, x + 15.f, "Oak", "texture2", "mesh2");
      }
   }

   forest.DisplayTrees();
   TreeType::PrintTreeTypeCounter();

   return 0;
}