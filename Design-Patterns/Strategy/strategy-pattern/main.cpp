/*
* Implement a strategy for printing a list of items in different formats.
* For this example, we'll use Markdown (MD) and HTML.
*/

#include <sstream>
#include <string>

enum class OutputFormat
{
   markdown,
   html
};

/*
* There are different ways of printing a list in MD (*) and HTML (<ul><li>asdasdads</li></ul>), 
*  so for that we'll have 3 different methods in our strategy.
*/
struct ListStrategy
{
   // start and end won't be pure virtual. Instead they'll have a default implementation since some formats don't need 
   //  start and end, such as MD.
   //  We're using the "interface segregation principal", which allows the inheritance avoid implementing things they don't need.
   // addListItem must be implemented by the children since they need to add the items in their list. For that we'll make it pure virtual.
   virtual void start(std::ostringstream& oss) {}
   virtual void addListItem(std::ostringstream& oss, const std::string& item) = 0;
   virtual void end(std::ostringstream& oss) {}
};

int main(int ac, char* av[])
{

   return 0;
}