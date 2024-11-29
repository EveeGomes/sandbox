#include <iostream>
#include <climits> // for INT_MIN


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


int main()
{
   /** 2. Find the Second Largest Element. 
   * Write a program to find the second largest element in an array without sorting it.
   * Example:
   *
   * Input: arr = [5, 1, 3, 2, 4]
   * Output: 4
   * Hint: Use two variables to track the largest and second largest elements.
   */

   /** 
   * 1. traverse the array;
   * 2. check if the current element is greater or less than the next (if looping forward);
   * 3. it it is, store the element in a variable, say largest;
   * 4. check if current element is greater than largest
   * 5. secLargest assign 0?
   * 
   * So instead of step 2, outside the loop store the first element in the variable "largest"? - yes
   * 6. now check if secLargest is less than largest but greater than the current element.
   * 7. or secLargest is less than largest - proceed
   * 8. 
   * 
   * 
   * second largest is a number that is less than largest, but greater than any other element.
   * 
   * so:
   * 1. initilaize both largest and secLargest to INT_MIN
   * 2. check if current element is > than largest
   * 3. if it is, store the old value of largest into secLargest and update largest to be the current element
   * 4. else if the current element is greater than secondLargest, AND NOT EQUAL to largest, update secondLargest to the current element!
   */

   int arr[5]{ 0, 1, 8, 2, 9 };
   int largest = INT_MIN;
   int secLargest = INT_MIN;

   for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
   {
      if (arr[i] > largest)
      {
         // Update second largest to current largest (since we'll change largest!)
         secLargest = largest;
         // Update largest to current element!
         largest = arr[i];
      }
      else if (arr[i] > secLargest && arr[i] != secLargest)
      {
         // Update second largest to the current element in this case
         secLargest = arr[i];
      }

      //if (secLargest < arr[i]) // else = if (arr[i] < largest) // secLargest < largest
      //{
      //   if (arr[i] != largest && secLargest < largest)
      //   {
      //      secLargest = arr[i];
      //   }


      //   //if (arr[i] > secLargest)
      //   //{
      //   //   secLargest = arr[i];
      //   //}
      //   
      //   //secLargest = arr[i]; 


      //   //if (arr[i] > arr[i + 1]) // check if i + 1 isn't out of bound: (i + 1) < (sizeof(arr) / sizeof(int)
      //   //{
      //   //   if ((i + 1) < (sizeof(arr) / sizeof(int)))
      //   //   {
      //   //      secLargest = arr[i];
      //   //   }
      //   //   
      //   //}
      //}
   }

   //secLargest = 0;
   //for (int i = 0; i < ARR_SIZE; ++i)
   //{
   //   if (arr[i] > secLargest && secLargest < largest)
   //   {
   //      secLargest = arr[i];
   //   }
   //}

   // Check if second largest wasn's found:
   if (secLargest == INT_MIN)
   {
      std::cout << "No second largest element found." << std::endl;
      return -1; // to indicate failure!
   }


   std::cout << "The largest element is: " << largest << std::endl;
   std::cout << "The second largest element is: " << secLargest << std::endl;

   return 0;
}