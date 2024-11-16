#include <iostream>

int main()
{
   int a[] = { 1, 4, 45, 6, 0, 19 };
   int x = 51;
   int aSize = sizeof(a) / sizeof(a[0]);

   int* ptrStart = a;
   int* ptrEnd = a;
   int wind_sum = 0;
   int wind_length = 0;

   //std::cout << a[*ptrEnd];
   //std::cout << *ptrEnd;

   //std::cout << *(++ptrEnd);


   while (wind_sum <= x)
   {
      //wind_sum += a[*ptrEnd];
      wind_sum += *ptrEnd;

      if (wind_sum <= x) // <=?
      {
         // increment end pointer
         ptrEnd++;
         // increment wind length
         wind_length++;
      }
   }
   std::cout << wind_sum;

   // when wind_sum is > x, record the length of the window (?)

   // now, incremement ptrStart until the sum is less or equal to x
   while (wind_sum > x)
   {
      wind_sum -= *ptrStart;

      if (wind_sum > x)
      {
         ptrStart++;
         wind_length--;
      }
   }
   std::cout << wind_sum << std::endl;
   std::cout << wind_length;

   // restart ptrEnd++ loop -> for the length of the array? Then, use for loop to encapsulate the two whiles?

   return 0;
}
