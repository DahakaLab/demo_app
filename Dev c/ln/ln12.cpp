#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Human
{
      public:
             int age, weight;
             string name;
             void print()
             {
                  cout<<name<<endl<<age<<endl<<weight<<endl;
             }
};

int main()
{
    Human a;
    a.age = 33;
    a.name = "Dima";
    a.weight = 80;
    a.print();
    getch();
}
