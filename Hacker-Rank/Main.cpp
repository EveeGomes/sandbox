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
   // Largests ints in each inner deque
   std::deque<int> largests{};

   int lengthFirst{};
   int lengthInner{};
   int firstInts{};
   int T{};


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


      // Used in the loop to populate inner deques
      int indexB = 0;
      // Now, populate the inner deques
      for (int i = 0; i < (first.size() - (first.size() % lengthInner)); i++)
      {
         // create an empty inner deque to use/populate it in the next loop
         B.push_back(std::deque<int>());
         indexB = i;
         if (i > first.size()) std::cout << "i > first.size()\n";

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
      for (const int& large : largests)
      {
         std::cout << large << " ";
      }
      std::cout << std::endl;

      // Clear every deque to start fresh in each iteration of while loop
      first.clear();
      B.clear();
      largests.clear();

      T--;
   }

   return 0;
}


3
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10
60 60
3354 2690 4429 2291 5046 3551 1170 1573 4810 6681 8168 5718 4532 4743 5371 9175 6251 5925 9179 6675 1568 8741 6523 2546 7964 4159 8028 9576 6413 7805 9611 6537 4918 6261 3910 5018 5815 4489 6851 9683 1120 6741 8989 6131 6737 8695 9494 118 4371 4642 1590 3712 5310 5998 1428 8119 2526 4418 4918 1660


3
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10
100 60
3354 2690 4429 2291 5046 3551 1170 1573 4810 6681 8168 5718 4532 4743 5371 9175 6251 5925 9179 6675 1568 8741 6523 2546 7964 4159 8028 9576 6413 7805 9611 6537 4918 6261 3910 5018 5815 4489 6851 9683 1120 6741 8989 6131 6737 8695 9494 118 4371 4642 1590 3712 5310 5998 1428 8119 2526 4418 4918 1660 766 4512 7365 4911 2374 8642 6355 5894 1475 4996 2480 170 5178 6128 2141 4744 298 9748 5212 1879 6367 349 8118 8178 7087 5114 1223 3503 3121 284 6357 2488 7529 3991 3164 9085 99 8298 6977 692