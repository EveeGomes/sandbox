#include <iostream>

/** 
* From: https://www.studytrigger.com/article/practice-problems-on-array/
*/
int main()
{
   /** Reverse the Elements of an Array Without Additional Memory */ 

   const int size = 5;
   int arr[size]{};
   int tempElm{};
   int start = 0;
   int end = size - 1;

   std::cout << "Enter " << size << " integers:\n";

   for (int i = 0; i < size; ++i)
   {
      std::cin >> arr[i];
   }

   /** 
   * [1, 2, 3, 4, 5]
   * [5, 4, 3, 2, 1]
   * 
   * Reversing means swapping the first element with the last, the second with the second-to-last and so on until the middle is reached!
   * Since there's no way to use additional memory, two pointers are needed: start, that starts at the beginning of the array i = 0.
   *  Another point: end that starts at the end i = size - 1.
   * 
   * As we need to move towards the middle, start should move forward, i.e. add 1, while end should move backwards, subtract 1.
   * They reach the middle when start is no longer less than end! So that's the condition to stop!
   * 
   * https://chatgpt.com/share/673c8b17-4b98-800a-ac03-1d82582b84ed
   */

   while (start < end)
   {
      tempElm = arr[start];
      arr[start] = arr[end];
      arr[end] = tempElm;

      start++;
      end--;
   }

   for (const int& elm : arr)
   {
      std::cout << elm << " ";
   }

   return 0;
}