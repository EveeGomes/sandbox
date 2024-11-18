#include <iostream>
#include <vector>
#include <iterator>
#include <deque>


// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, returns size+1.
int smallestSubWithSum(std::vector<int>& arr, int x) {

   int start = 0;
   int end = 0;
   int windSum = 0;
   int windLength = 0;
   int result = arr.size() + 1; // used to print out "Not possible" at the end in case there's not a subarray that satisfy the condition

   // Traverse the vector
   while (end < arr.size())
   {
      // Until wind_sum is smaller than or equal to x, continue adding array elements to it
      while (windSum <= x && end < arr.size())
      {
         windSum += arr[end++];
      }

      // If windSum turns to be greater than x, update the result to hold the length of the smallest subarray
      // Increase start pointer
      while (windSum > x && start < arr.size())
      {
         result = std::min(result, end - start);
         windSum -= arr[start++];
      }
   }

   return result;
}

void printVector(std::vector<int>& arr, int result, int x)
{
   std::deque<int> window{};
   std::vector<int> subArray{};
   int currSum = 0;

   // Add first window
   for (int i = 0; i < result; i++) // indices: 0, 1, 2
   {
      subArray.push_back(arr[i]);
      currSum += arr[i];
   }

   for (int i = result; i < arr.size(); i++) // i = result = 3
   {
      if (currSum < x)
      {
         // remove first, add the next element from arr starting from the current after result
         subArray.erase(subArray.begin());
         // add the next element
         subArray.push_back(arr[i]);
         // add to the sum
         currSum += arr[i];
      }
   }

   for (const int& elm : subArray)
   {
      std::cout << elm << " ";
   }
   // 1 4 45
   // 4 45 6
}


int main() {
   // 1, 4, 45, 6, 0, 19 x = 51 Minimum length subarray is {4, 45, 6}
   // 1, 11, 100, 1, 0, 200, 3, 2, 1, 250 x = 280 Minimum length subarray is {100, 1, 0, 200}
   // 1, 10, 5, 2, 7 x = 9 Minimum length subarray is {10}

   std::vector<int> arr = { 1, 10, 5, 2, 7 };
   int x = 9;

   int res = smallestSubWithSum(arr, x);
   (res == arr.size() + 1) ? std::cout << "Not possible\n" : std::cout << res << std::endl;

   printVector(arr, res, x);

   return 0;
}
