#include <iostream>
#include <deque>
#include <algorithm>
#include <set>


int main()
{

   std::deque<std::deque<int>> B;
   
   // length of the deque
   //int length = 5;

   // size of the inner deques
   //int l = 4;

   int lengthFirst{};
   int l{};
   int firstInts{};

   std::cin >> lengthFirst >> l;

   std::deque<int> first{};
   // populate first
   for (int i = 0; i < lengthFirst; i++)
   {
      std::cin >> firstInts;
      first.push_back(firstInts);
   }

   //std::deque<int> first{ 3, 4, 5, 8, 1, 4, 10 };
   // Add empty subdeques before adding elements to these subdeques (inner deque):
   //for (int i = 0; i < first.size() - 1; i++) // i < length;
   //{
   //   // add empty inner deque to B
   //   B.push_back(std::deque<int>());
   //}

   //int first[7] = { 3, 4, 5, 8, 1, 4, 10 };
   //int first[5] = { 3, 4, 6, 3, 4 };



   // Now, populate the inner deques
   int indexB = 0;
   //int iterate = first.size() - (first.size() % l); // ok

   for (int i = 0; i < (first.size() - (first.size() % l)); i++) // 4
   {
      // create an empty inner deque to use/populate it in the next loop
      B.push_back(std::deque<int>());
      indexB = i; // 0, 1, 2, 3

      for (int j = 0; j < l; j++)
      {
         B[i].push_back(first[indexB]);
         indexB++;
      }

      //indexB++;
   }

   // find the greatest value in each inner deque
   //std::deque<int>::iterator innerIt = B[0].begin();

   //std::deque<int>::iterator largest = std::max_element(innerIt, B[0].end());
   //int large = *std::max_element(innerIt, B[0].end());

   std::deque<int> largests;
   //std::set<int> largests{};

   for (int i = 0; i < B.size(); i++)
   {

      largests.push_back(*std::max_element(B[i].begin(), B[i].end()));

      // no need for this inner loop since I just need the max in each inner deque
      // 
      //for (int j = 0; j < B[i].size(); j++)
      //{
      //   largests.push_back(*std::max_element(B[i].begin(), B[i].end()));
      //   //largests.insert(*std::max_element(B[i].begin(), B[i].end()));
      //}
   }



   // for debug only:
   for (int i = 0; i < B.size(); i++)
   {
      for (int j = 0; j < B[i].size(); j++)
      {
         std::cout << B[i][j] << " ";
      }
      std::cout << std::endl;
   }

   std::cout << std::endl;
   std::cout << "Largests: ";
   for (const int large : largests)
   {
      std::cout << large << " ";
   }

   return 0;
}