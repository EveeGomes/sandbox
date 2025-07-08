/*
* Implement a strategy for printing a list of items in different formats.
* For this example, we'll use Markdown (MD) and HTML.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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

struct MarkdownListStrategy : ListStrategy
{

};

struct HtmlListStrategy : ListStrategy
{

};

/*
* Have a text process component that'll help print those lists in a proper fashion.
* It'll allow us to use a particular strategy to print a list of items.
* 
* So how to refer to the strategy itself? Two approaches:
* Dynamic approach -> have a variable of a strategy type;
* Static approach -> take the strategy type as a template argument.
* 
* 
*/
struct TextProcessor
{
   // DYNAMIC APPROACH

   // Make a utility function for clearing the text processes.
   void clear()
   {
      oss.str("");
      oss.clear();
   }

   // Use the strategy to append items.
   void appendList(const std::vector<std::string>& items)
   {
      // Use the strategy reference here. 
      listStrategy->start(oss);
      for (auto& item : items)
      {
         listStrategy->addListItem(oss, item);
      }

      listStrategy->end(oss);
   }
   
   // Add some functionality of specifying what kind of strategy we want - we do that by using the enum.
   // So we take a format and depending on what format we'll create an instance of it and set to the listStrategy.
   void setOutputFormat(const OutputFormat& format)
   {
      switch (format)
      {
      case OutputFormat::markdown:
         listStrategy = std::make_unique<MarkdownListStrategy>();
         break;
      case OutputFormat::html:
         listStrategy = std::make_unique<HtmlListStrategy>();
      }
   }

   std::string str() const
   {
      return oss.str();
   }

private:
   std::ostringstream oss; // we'll fill in.
   std::unique_ptr<ListStrategy> listStrategy;
};


int main(int ac, char* av[])
{
   std::vector<std::string> items{ "foo", "bar", "baz" };

   TextProcessor textProcessor;
   textProcessor.setOutputFormat(OutputFormat::markdown);
   textProcessor.appendList(items);
   std::cout << textProcessor.str() << "\n";

   textProcessor.clear();

   textProcessor.setOutputFormat(OutputFormat::html);
   textProcessor.appendList(items);
   std::cout << textProcessor.str() << "\n";

   return 0;
}