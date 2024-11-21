#include <iostream>


/**
* From: https://chatgpt.com/c/673c8794-cfb4-800a-b798-73e06c51b299
*/

#define ARR_SIZE 5

int main()
{
   /** 2. Rotate an array to the right by one position. */

   int arr[ARR_SIZE]{ 1, 2, 3, 4, 5 };
   int rotatePosition = 1;
   
   // store the last element in a temp variable
   int last = arr[ARR_SIZE - 1];

   // shift all other elements to the right (it has to loop backward otherwise the newly shifted value overwrites the original value)
   for (int i = ARR_SIZE - 1; i > 0; --i) //(int i = 0; i < ARR_SIZE; ++i)
   {
      //if (i + 1 < ARR_SIZE) arr[i + 1] = arr[i];
      arr[i] = arr[i - 1];
   }

   // place the last element stored in temp at the start
   arr[0] = last;

   for (const int& elm : arr)
   {
      std::cout << elm << " ";
   }

   return 0;
}