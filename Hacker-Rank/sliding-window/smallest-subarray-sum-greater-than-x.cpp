#include <iostream>
#include <vector>
#include <iterator>




int main()
{
   int* ptrStart = a;
   int* ptrEnd = a;
   int wind_sum = 0;
   int wind_length = 0;
   
   //
   std::vector<int> intVec = { 1, 4, 45, 6, 0, 19 };
   int x = 51;
   
   std::vector<int>::iterator itStart = intVec.begin();
   std::vector<int>::iterator itEnd = intVec.begin();
   int windSum = 0;
   int windLength = 0;
   int result = arr.size() + 1; // used to print out "Not possible" at the end in case there's not a subarray that satisfy the condition

   // Traverse the vector
   while (itEnd < intVec.end()) // < intVec.End() - 1 ??
   {
      // Until wind_sum is smaller than or equal to x, continue adding array elements to it
      while (windSum <= x && itEnd < intVec.end()) // < intVec.End() - 1 ? ?
      {
         windSum += *(itEnd++);
         if (windSum <= x) windLength++;
      }

      // If windSum turns to be greater than x, update the result to hold the length of the smallest subarray
      // Increase start pointer 
      while (windSum > x && itStart < intVec.end()) // < intVec.End() - 1 ? ?
      {
         result = std::min(result, windLength);
         windSum -= *(itStart++);
      }
   }

   //while (windLength--)
   //{
   //   std::cout << *(itStart++) << ", ";
   //}
   return result;

   



   if (wind_sum <= x)
   {
      //wind_sum += a[*ptrEnd];
      wind_sum += *ptrEnd;
      //// increment wind_length as the sum happened?
      //wind_length++;

      if (wind_sum <= x) // <=?
      {
         // increment end pointer
         ptrEnd++;
         // increment wind length
         wind_length++;
      }
   }
   std::cout << wind_sum << std::endl;
   std::cout << wind_length << std::endl;

   // when wind_sum is > x, record the length of the window (?)

   // now, incremement ptrStart until the sum is less or equal to x
   if (wind_sum > x)
   {
      wind_sum -= *ptrStart;

      if (wind_sum > x)
      {
         ptrStart++;
         //wind_length--; // no need
      }
   }
   std::cout << wind_sum << std::endl;
   std::cout << wind_length;

   // restart ptrEnd++ loop -> for the length of the array? Then, use for loop to encapsulate the two whiles?

   std::cout << "\n Start: " << *ptrStart << ", End: " << *ptrEnd;

   return 0;
}
