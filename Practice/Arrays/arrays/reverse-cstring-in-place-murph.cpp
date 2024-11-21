#include <iostream>


/**
* From: https://chatgpt.com/c/673c8794-cfb4-800a-b798-73e06c51b299
*/
int main()
{
   /** 1. Reverse a string in place (similar to the array problem). */

   const int size = 6; // 5 + '\0'
   // create a dynamic array of chars on the heap with size size; ptrArr points to the beginning of this array!
   char* ptrArr = new char[size];

   for (int i = 0; i < size - 1; ++i) // i < size - 1 instead of i < size -> for size - 1 is the null terminator!!!!
   {
      std::cin >> ptrArr[i];
   }
   // add null terminator to the end of the array (c-string)
   ptrArr[size - 1] = '\0';

   char temp{};
   int start = 0;
   int end = size - 2; // so it doesn't reach the null terminator which is located at index 5 (size - 1)?

   while (start < end)
   {
      temp = ptrArr[start];
      ptrArr[start] = ptrArr[end];
      ptrArr[end] = temp;
      start++;
      end--;
   }

   for (int i = 0; i < size; ++i)
   {
      std::cout << ptrArr[i];
   }

   // used new[], then use delete[]
   delete[] ptrArr;

   return 0;
}