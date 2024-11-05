#include <iostream>
#include <deque>


int main()
{

   std::deque<std::deque<int>> B;
   //int length = 7;
   int l = 4;

   // Add empty subdeques before adding elements to these subdeques (inner deque):
   for (int i = 0; i < l; i++)
   {
      // add empty inner deque to B
      B.push_back(std::deque<int>());
   }

   int first[7] = { 3, 4, 5, 8, 1, 4, 10 };

   // Now, populate the inner deques
   int indexB = 0;

   for (int i = 0; i < l; i++)
   {
      indexB = i;

      for (int j = 0; j < l; j++)
      {
         B[i].push_back(first[indexB]);
         indexB++;
      }

      //indexB++;
   }


   for (int i = 0; i < B.size(); i++)
   {
      for (int j = 0; j < B[i].size(); j++)
      {
         std::cout << B[i][j] << " ";
      }
      std::cout << std::endl;
   }

   return 0;
}