#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, returns size+1.
int smallestSubWithSum(vector<int>& arr, int x) {
   //int currSum = 0, res = arr.size() + 1;
   //int start = 0, end = 0;

   //// Traverse the array
   //while (end < arr.size()) {

   //   // Keep adding array elements while currSum 
   //   // is smaller than or equal to x
   //   while (currSum <= x && end < arr.size()) {
   //      currSum += arr[end++];
   //   }

   //   // If currSum becomes greater than x, update
   //   // res if needed
   //   while (currSum > x && start < arr.size()) {
   //      res = min(res, end - start);
   //      currSum -= arr[start++];
   //   }
   //}
   //return res;

   std::vector<int> subArray{};
   std::vector<int>::iterator itStart = arr.begin();
   std::vector<int>::iterator itEnd = arr.begin();
   int windSum = 0;
   int windLength = 0;
   int result = arr.size() + 1; // used to print out "Not possible" at the end in case there's not a subarray that satisfy the condition

   // Traverse the vector
   while (itEnd < arr.end() - 1) // < intVec.End() - 1 ??
   {
      // Until wind_sum is smaller than or equal to x, continue adding array elements to it
      while (windSum <= x && itEnd < arr.end() - 1) // < intVec.End() - 1 ? ?
      {
         // subArray.push_back(*itEnd);              
         windSum += *(itEnd++);
         
         if (windSum <= x)
         {
            windLength++;
            subArray.push_back(*itEnd);
         }
         std::cout << *itEnd << " ";
      }
      //std::cout << subArray.size() << std::endl;

      // If windSum turns to be greater than x, update the result to hold the length of the smallest subarray
      // Increase start pointer 
      while (windSum > x && itStart < arr.end() - 1) // < intVec.End() - 1 ? ?
      {
         result = std::min(result, windLength);

         // remove the element from subArray that's also been subtracted, only if 
         if (result != windLength) subArray.erase(subArray.begin());
         windSum -= *(itStart++);
      }
   }

   for (int& elm : subArray)
   {
      std::cout << elm << ", ";
   }
   std::cout << std::endl;

   //while (windLength--)
   //{
   //   std::cout << *(itEnd++) << ", ";
   //}
   return result;

}

int main() {
   vector<int> arr = { 1, 4, 45, 6, 0, 19 };
   int x = 51;

   ////std::cout << *arr.begin();
   //std::vector<int>::iterator it;
   //it = arr.begin();
   //std::cout << *(it++) << std::endl;
   //std::cout << *(++it);

   int res = smallestSubWithSum(arr, x);
   (res == arr.size() + 1) ? cout << "Not possible\n" : cout << res << endl;

   return 0;
}
