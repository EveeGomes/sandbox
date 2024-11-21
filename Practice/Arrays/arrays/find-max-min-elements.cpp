#include <iostream>


/**
* From: https://chatgpt.com/c/673c8794-cfb4-800a-b798-73e06c51b299
*/

#define ARR_SIZE 5

int main()
{
   /** 3. Find the maximum and minimum elements in an array using a single loop. */

   int arr[ARR_SIZE]{};

   for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
   {
      std::cin >> arr[i];
   }

   // assign the first element of the array to max and min to compare in the loop and reassign as needed
   int max = arr[0];
   int min = arr[0];

   for (int i = 0; i < ARR_SIZE; ++i)
   {
      if (arr[i] > max) max = arr[i];
      if (arr[i] < min) min = arr[i];
   }

   std::cout << "Max: " << max << " and Min: " << min;

   return 0;
}