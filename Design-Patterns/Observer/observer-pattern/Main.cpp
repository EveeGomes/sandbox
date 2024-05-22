// From Udemy Design Patterns in Modern C++

// Observer: the thing that monitors something
// Observable: the component is the one to be obeserved

class Person // observable
{
   int m_age;
public:
   Person(int age) { m_age = age; }
   
   int get_age() const
   {
      return m_age;
   }

   void set_age(int age)
   {
      m_age = age; // in the video he uses Person::m_age = age;
   }
};

int main(int arg, char* args[])
{


   return 0;
}