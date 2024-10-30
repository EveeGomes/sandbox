#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <sstream>

int main() {
   int N, Q;
   std::cin >> N >> Q;
   std::cin.ignore();

   std::map<std::string, std::map<std::string, std::string>> tagMap; // Store tag structure and attributes
   std::stack<std::string> tagStack; // Track nested tags for full path generation
   std::string currentPath;

   // Parse HRML lines
   for (int i = 0; i < N; ++i) {
      std::string line;
      std::getline(std::cin, line);

      if (line[1] != '/') { // Opening tag
         std::istringstream iss(line);
         std::string tag, attr, value;
         char ignoreChar;

         // Parse the opening tag name
         iss >> ignoreChar >> tag; // Reads "<tagname"
         tag = tag.substr(0, tag.find('>')); // Remove trailing '>' if present

         // Update the current path based on nesting
         if (!currentPath.empty()) {
            currentPath += "." + tag;
         }
         else {
            currentPath = tag;
         }
         tagStack.push(currentPath); // Push the current path to the stack

         // Collect attributes for the tag
         std::map<std::string, std::string> attributes;
         while (iss >> attr >> ignoreChar >> value) { // Read attributes
            value.pop_back(); // Remove trailing '"'
            value.erase(value.begin()); // Remove leading '"'
            attributes[attr] = value;
         }
         tagMap[currentPath] = attributes; // Map the path to its attributes

      }
      else { // Closing tag
         tagStack.pop(); // Pop the tag from stack
         if (!tagStack.empty()) {
            currentPath = tagStack.top(); // Update current path to parent
         }
         else {
            currentPath.clear();
         }
      }
   }

   // Process queries
   for (int i = 0; i < Q; ++i) {
      std::string query;
      std::getline(std::cin, query);

      // Separate the tag path and attribute from query
      size_t pos = query.find('~');
      std::string tagPath = query.substr(0, pos);
      std::string attribute = query.substr(pos + 1);

      // Look up attribute value, if exists, otherwise "Not Found!"
      if (tagMap.count(tagPath) && tagMap[tagPath].count(attribute)) {
         std::cout << tagMap[tagPath][attribute] << std::endl;
      }
      else {
         std::cout << "Not Found!" << std::endl;
      }
   }

   return 0;
}
