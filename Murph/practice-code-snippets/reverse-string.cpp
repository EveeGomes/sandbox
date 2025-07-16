#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> // std::reverse

std::string reverseWords(const std::string& sentence)
{
   std::string word{};
   //std::string reversed{};
   std::ostringstream oss{};
   std::vector<std::string> words{};
   
   // Turns the string into a istringstream, which allows me to read it word by word!
   std::istringstream iss(sentence);

   // Reads each word separated by whitespace
   while (iss >> word)
   {
      words.push_back(word);
   }

   std::reverse(words.begin(), words.end());

   //for (size_t i = 0; i < words.size(); ++i)
   //{
   //   reversed += words[i];

   //   if (i != words.size() - 1)
   //   {
   //      reversed += ' ';
   //   }
   //}

   for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); ++it)
   {
      oss << *it;

      if (it != std::prev(words.end()))
      {
         oss << ' ';
      }
   }

   return oss.str();
}

int main()
{
   std::string sentence = "we are far away";
   std::string reversedSentence{};
   reversedSentence = reverseWords(sentence);

   std::cout << reversedSentence << std::endl;

   return 0;
}