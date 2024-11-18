#include <iostream>

/** 
* From: https://www.studytrigger.com/article/practice-problems-on-array/
*/
int main()
{
   /** Find the sum of all elements in a 1 - D array */ 

   const int size = 5;
   int arr[size] = {};

   int arrSum{};

   // ask user to enter integers to the array
   std::cout << "Enter " << size << " integers: \n";
   for (int i = 0; i < size; i++)
   {
      std::cin >> arr[i];
   }

   // Find the sum of all elements
   for (int i = 0; i < size; i++)
   {
      arrSum += arr[i];
   }

   std::cout << "The sum of all elements is: " << arrSum;


   return 0;
}