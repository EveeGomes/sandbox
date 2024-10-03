#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
   // count the number of positive values, and save it in a variable
   // do the same for negative values
   // and zero values
   // save the size of the array in a variable as well
   // then, do the ratio of each using precision of the float number: 
   //  6 digits after the decimal

   double positive = 0.;
   double positiveRatio = 0.;
   double negative = 0.;
   double negativeRatio = 0.;
   double zero = 0.;
   double zeroRatio = 0.;
   int arrSize = arr.size();

   for (int i = 0; i < arrSize; i++)
   {
      if (arr[i] > 0)
      {
         positive++;
      }
      else if (arr[i] < 0)
      {
         negative--;
      }
      else
      {
         zero++;
      }
   }
   // positive
   positiveRatio = positive / arrSize;
   std::cout << std::setprecision(6) << positiveRatio << std::endl;

   // negative
   negativeRatio = negative / arrSize;
   std::cout << std::setprecision(6) << std::abs(negativeRatio) << std::endl;

   // zero
   zeroRatio = zero / arrSize;
   std::cout << std::setprecision(6) << zeroRatio << std::endl;
}

int main()
{
   string n_temp;
   getline(cin, n_temp);

   int n = stoi(ltrim(rtrim(n_temp)));

   string arr_temp_temp;
   getline(cin, arr_temp_temp);

   vector<string> arr_temp = split(rtrim(arr_temp_temp));

   vector<int> arr(n);

   for (int i = 0; i < n; i++) {
      int arr_item = stoi(arr_temp[i]);

      arr[i] = arr_item;
   }

   plusMinus(arr);

   return 0;
}

string ltrim(const string& str) {
   string s(str);

   s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
   );

   return s;
}

string rtrim(const string& str) {
   string s(str);

   s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end()
   );

   return s;
}

vector<string> split(const string& str) {
   vector<string> tokens;

   string::size_type start = 0;
   string::size_type end = 0;

   while ((end = str.find(" ", start)) != string::npos) {
      tokens.push_back(str.substr(start, end - start));

      start = end + 1;
   }

   tokens.push_back(str.substr(start));

   return tokens;
}
