#include <iostream>
#include <type_traits>
#include <string>


/**
* From: https://chatgpt.com/c/673c8794-cfb4-800a-b798-73e06c51b299
*/

#define ARR_SIZE 5

template<typename T>
void printThis(const T& toPrint)
{
   std::cout << toPrint << std::endl;
}

template<typename T>
void printPointer(T* ptr)
{
   std::cout << "Pointer's address: " << &ptr << std::endl;
   std::cout << "Address to where this pointer points to: " << static_cast<const void*>(ptr) << std::endl;

   if (std::is_same<T, const char>::value) // instead of const char*
   {
      std::cout << "Content in the address this pointer points to: " << ptr << std::endl;
   }
   else
   {
      std::cout << "Content in the address this pointer points to: " << *ptr << std::endl;
   }
}

bool IsPalindrome(char originalWord[], int wordLength) // can't be const char*
{

   char reversedWord[50] = {'\0'};
   int reversedIndex = 0;

   for (int i = wordLength - 2; i >= 0; --i) // i >= 0 instead of i > 0 // wordLenght - 2 because - 1 is the null terminator!
   {
      reversedWord[reversedIndex] = originalWord[i];

      //std::cout << reversedWord[reversedIndex];

      reversedIndex++;   
   }
   // add null terminator to reversedWord? 

   std::cout << std::endl;

   // compare both 
   for (int i = 0; i < wordLength; ++i)
   {
      if (reversedWord[i] != originalWord[i])
      {
         //std::cout << reversedWord[i];
         return false;
      }
      //else
      //{
      //   std::cout << reversedWord[i];
      //   return false;
      //}
   }

   return true;
}

int main()
{
   /** 4. Write a function to check if an array is a palindrome. */

   // civic

   /** 
   * Palindrome: The word is the same when reversed.
   * 
   * 1. Reverse the array in place (first element swap with last, second with second last etc until the middle is reached)
   *  1.1 create two pointers: start and end
   *  1.2 start points to the beginning of the array (index 0), end points to the end (index size - 1)
   *  1.3 
   * 
   * Actually, reverse the array by creating another array, say reversedArray to check if that one is the same as the original one.
   * 1. create a string;
   * 2. add the content of original string to the reversedArray in backward order, so it's reversed;
   * 3. compare both;
   * 4. if they're the same return true; otherwise false.
   */

   //char original[] = "civic";
   char original[] = "create";

   if (IsPalindrome(original, sizeof(original)/sizeof(char)))
   {
      std::cout << "It's Palindrome" << std::endl;
   }
   else
   {
      std::cout << "It's not Palindrome" << std::endl;
   }

   return 0;
}