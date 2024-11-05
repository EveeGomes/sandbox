#include <iostream>
#include <deque>
#include <algorithm>
#include <set>


int main()
{
   // Deque with inner deques
   std::deque<std::deque<int>> B{};
   // Deque that receives elements from user
   std::deque<int> first{};

   std::deque<int> largests{};
   int lengthFirst{};
   int lengthInner{};
   int firstInts{};
   int T{};
   // Used in the loop to populate inner deques
   int indexB = 0;

   // Get user input of how many tests:
   std::cin >> T;

   while (T > 0)
   {
      // Get user input of lengths of the first deque and inner deques
      std::cin >> lengthFirst >> lengthInner;

      // Populate first
      for (int i = 0; i < lengthFirst; i++)
      {
         std::cin >> firstInts;
         first.push_back(firstInts);
      }

      // Now, populate the inner deques
      for (int i = 0; i < (first.size() - (first.size() % lengthInner)); i++)
      {
         // create an empty inner deque to use/populate it in the next loop
         B.push_back(std::deque<int>());
         indexB = i;

         for (int j = 0; j < lengthInner; j++)
         {
            B[i].push_back(first[indexB]);
            indexB++;
         }
      }

      // Find the largest numbers in each inner deque 
      for (int i = 0; i < B.size(); i++)
      {
         largests.push_back(*std::max_element(B[i].begin(), B[i].end()));
      }

      //std::cout << std::endl;
      //std::cout << "Largests: ";
      for (const int large : largests)
      {
         std::cout << large << " ";
      }
      std::cout << std::endl;

      // Clear every deque to start again in each iteration of while
      first.clear();
      B.clear();
      largests.clear();

      T--;
   }

   return 0;
}