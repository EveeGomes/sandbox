#include <iostream>
#include <deque>
#include <vector>


int main()
{
   // Number of tests coming from "user"/test
   int T{};
   std::cin >> T;

   while (T > 0) // or T-- ?
   {
      // window to slide through numbers. It holds the indices of elements in numbers vector
      std::deque<int> window{};

      // Largests ints in each window
      std::vector<int> largests{};

      int lengthNumbers{};
      int windowLength{};

      // Get lengths of numbers and window
      std::cin >> lengthNumbers >> windowLength;

      // Array of numbers coming from "user"/test
      std::vector<int> numbers(lengthNumbers);
      // Populate numbers
      for (int i = 0; i < lengthNumbers; ++i)
      {
         std::cin >> numbers[i];
      }

      // Process each element in numbers
      for (int i = 0; i < lengthNumbers; ++i)
      {
         // Remove elements out of the current window
         if (!window.empty() && window.front() <= i - windowLength)
         {
            // Remove the first element if it's lower than the current index minus this window's length (it's older), remove it.
            //  That ensures that the window only has indices of elements within the current window.
            window.pop_front();
         }

         // Remove index (window element) from the window that represents a smaller element than the current index represents in numbers!
         while (!window.empty() && numbers[window.back()] <= numbers[i])
         {
            window.pop_back();
         }

         // Add the current element (current index) to the back of the window
         window.push_back(i);

         // For the current window (as soon as a full window is achieved: the current index is >= windowLength - 1), the element at the front
         //  represents the index of the element in numbers that's the largest one!
         if (i >= windowLength - 1) // means the window is filled, therefore we're in the current window
         {
            // Then, add the numbers element to the largest array using the index at the front in the window
            largests.push_back(numbers[window.front()]);
         }
      }

      // Now, print the maximum/largest values
      for (int& largest : largests)
      {
         std::cout << largest << " ";
      }
      std::cout << std::endl;

      T--; // if we use while (T--), this isn't needed
   }

   return 0;
}
