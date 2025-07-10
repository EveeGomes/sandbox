#include <iostream>
#include <stack>
#include <string>

void reverseString(const std::string& str)
{
   std::string reversedStr = "";
   std::stack<char> reversedChars;

   for (int i = 0; i < str.length(); ++i)
   {
      reversedChars.push(str[i]);
   }

   while (!reversedChars.empty())
   {
      reversedStr += reversedChars.top();
      reversedChars.pop();
   }

   std::cout << reversedStr << std::endl;

   //return reversedStr;
}


int main()
{
   std::string word = "faraway";
   reverseString(word);

   //std::stack<char> reversed;

   //for (int i = 0; i < word.length(); ++i)
   //{
   //   std::cout << word[i];
   //   reversed.push(word[i]);
   //}
   //std::cout << std::endl;
   //std::cout << "-------------" << std::endl;

   //while (!reversed.empty())
   //{
   //   std::cout << reversed.top();
   //   reversed.pop();
   //}

   return 0;
}