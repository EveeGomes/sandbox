#include <iostream>

/** 
* From: https://www.studytrigger.com/article/practice-problems-on-array/
*/
int main()
{
   /** Compute the average of elements in a 1-D array */ 

   const int size = 5;
   int arr[size]{};

   int average{};
   int arrSum{};

   std::cout << "Enter " << size << " integers: \n";
   for (int i = 0; i < size; i++)
   {
      std::cin >> arr[i];
      arrSum += arr[i];
   }

   average = arrSum / size;

   std::cout << "The average is: " << average;

   return 0;
}