#include <iostream>


/**
* From: https://chatgpt.com/c/673c8794-cfb4-800a-b798-73e06c51b299
*/

#define ARR_SIZE 5

int main()
{
   /** 1. Rotate an array to the left or right by a given number of positions. */

   int arr[ARR_SIZE]{ 1, 2, 3, 4, 5 };
   int rotatePositions{};
   int rotation{};

   std::cout << "Enter the number that correspind to the order of rotation: right = 1 or left = 2: ";
   std::cin >> rotation;
   std::cout << "Enter the number of positions to rotate: ";
   std::cin >> rotatePositions;
   
   while (rotatePositions--)
   {
      if (rotation == 1)
      {
         // Store the last element in a temp variable
         int last = arr[ARR_SIZE - 1];

         // Shift all other elements to the right (it has to loop backward otherwise the newly shifted value overwrites the original value)
         for (int i = ARR_SIZE - 1; i > 0; --i)
         {
            arr[i] = arr[i - 1];
         }

         // Place the last element stored in temp at the start
         arr[0] = last;
      }
      if (rotation == 2)
      {
         // Store the first element in a temp variable
         int first = arr[0];

         // Shift all elements to the left
         for (int i = 0; i < ARR_SIZE - 1; ++i)
         {
            arr[i] = arr[i + 1];
         }

         // Place the first element stored in the temp variable at the end
         arr[ARR_SIZE - 1] = first;
      }
   }

   // Print the array
   for (const int& elm : arr)
   {
      std::cout << elm << " ";
   }

   return 0;
}