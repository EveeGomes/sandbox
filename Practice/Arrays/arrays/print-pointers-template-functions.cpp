#include <iostream>
#include <type_traits>


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

void IsPalindrome(const char* word, int wordLength)
{

}

int main()
{
   /** 4. Write a function to check if an array is a palindrome. */

   // civic

   // pointer to a constant char or constant C-style string
   const char* word = nullptr;
   int* ptrInt = nullptr;
   ptrInt = new int{ 10 };

   // C-Style string
   char unConstWord[] = "Not Const Array";


   word = "Hello";
   printPointer<const char>(word);
   std::cout << std::endl;

   word = "World";
   printPointer<const char>(word);

   std::cout << std::endl;
   printPointer<int>(ptrInt);

   delete ptrInt;

   return 0;
}