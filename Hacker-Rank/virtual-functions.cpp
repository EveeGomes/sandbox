/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

#include <vector>
#include <string>
#include <sstream>

class Person
{
protected:
   std::string m_name{};
   int m_age{};
public:
   Person() {}
   virtual void getdata() { }
   virtual void putdata() 
   {
      std::cout << m_name << " " << m_age << " ";
   }
};

class Professor : public Person
{
   int m_publications{};
   int m_cur_id{};

public:
   Professor() 
   {
      s_count++;
      std::cout << "Professor #" << s_count << std::endl;
      getdata();
   }
   ~Professor()
   {
      std::cout << "Professor #" << s_count << " destroyed!\n";
      s_count--;
      std::cout << "Current s_count: " << s_count << std::endl;
      //std::cout << "Professor destroyed!\n";
   }
   // static variable to keep track of Professor instances
   static int s_count;
   // get input from the user: the name, age, and publication
   void getdata() override
   {
      // get input in a string
      std::string input{};
      std::getline(std::cin, input);

      // create a stringstream object to parse the data
      std::stringstream inputStream{ input };

      // extract each part and store in their respective member variables
      inputStream >> m_name >> m_age >> m_publications;

      m_cur_id = Professor::s_count;
   }
   // print the name, age, publications, and cur_id >>> Walter 56 99 1
   void putdata() override 
   {
      Person::putdata();
      std::cout 
         << m_publications << " " 
         << s_count;
   }
};
int Professor::s_count = 0;


/************** STUDENT **************/
class Student : public Person
{
   int m_marks[6]{};
   int m_cur_id{};

public:
   Student()
   {
      s_count++;
      std::cout << "Student #" << s_count << std::endl;
      // call putdata()? Use s_count++ to set m_cur_id
      getdata();
   }
   ~Student()
   {
      std::cout << "Student #" << s_count << " destroyed!\n";
      s_count--;
      std::cout << "Current s_count: " << s_count << std::endl;
   }
   // static variable to keep track of Student instances
   static int s_count;
   // get input from the user: the name, age, and marks
   void getdata() override
   {
      // get input in a string
      std::string input{};
      std::getline(std::cin, input);

      // create a stringstream object to parse the data
      std::stringstream inputStream{ input };

      // extract each part and store in their respective member variables
      inputStream >> m_name >> m_age;
      for (int i = 0; i < 6; i++)
      {
         inputStream >> m_marks[i];
      }

      m_cur_id = Student::s_count;
   }
   // print the name, age, sum of the marks, and cur_id >>> Jesse 18 403 1
   void putdata() override
   {
      Person::putdata();
      int marksSum = 0;
      for (int i = 0; i < 6; i++)
      {
         marksSum += m_marks[i];
      }
      std::cout
         << marksSum << " "
         << m_cur_id;
   }
};
int Student::s_count = 0;


int main()
{
   int numOfPersons = 0;
   std::cin >> numOfPersons;

   int typeOfPerson = 0;

   while (numOfPersons > 0)
   {
      std::cin >> typeOfPerson;
      if (typeOfPerson == 1)
      {
         // professor
         Professor professor1{};
         //professor1.getdata();

      }
      if (typeOfPerson == 2)
      {
         // student
         Student student1{};
         //student1.getdata();
      }

      numOfPersons--;
   }

   // those object will be destroyed once the while is over? YES!

   return 0;
}