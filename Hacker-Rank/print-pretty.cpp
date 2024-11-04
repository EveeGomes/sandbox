#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */

   // get the number of test cases from user
   int T{};
   std::cin >> T;

   double A{};
   double B{};
   double C{};

   while (T > 0)
   {
      // get double numbers
      std::cin >> A >> B >> C;

      // before printing, save ios flag state
      std::ios oldState(nullptr);
      oldState.copyfmt(std::cout);

      // print A: truncate and print out its hexadecimal representation (including 0x prefix) in lower case letters
      double truncatedA = std::trunc(A);
      std::cout
         << std::showbase
         << std::hex
         << std::nouppercase
         << static_cast<int>(truncatedA)
         << std::endl;

      // reset std::cout
      std::cout.copyfmt(oldState);

      // print B: print it out with 2 decimal places, use + or - to indicate if it's pos or neg number; right justified, left-padded with underscores so the printed result is exactly 15 characters wide.
      // format the output, then check the number sign
      std::cout
         << std::setw(15)
         << std::setprecision(2)
         << std::fixed
         << std::right
         << std::setfill('_')
         << std::showpos
         << B
         << std::endl;

      // reset flags
      std::cout.copyfmt(oldState);

      // print C: use exactly 9 decimal places, print out the number in scientific notation using upper case.
      std::cout
         << std::uppercase
         << std::setprecision(9)
         << std::fixed
         << std::scientific
         << C;

      T--;
   }

   return 0;
}
