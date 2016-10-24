#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Number
{
      public:
      string name;
      string number;
      Number(const Number &v):
                         name(v.name),
                         number(v.number){}
      Number (){};
      const Number &operator=(const Number &v)
      {
             name = v.name;
             number = v.number;
             return v;
      }
};

int main()
{
    ifstream f("ln16.txt");
    vector<Number> telBook;
    while(true)
    {
               Number t;
               f>>t.name;
               if(f.eof())
                          break;
               f>>t.number;
               if(f.eof())
                          break;
               telBook.push_back(t);
    }
    while(true)
    {
               cout<<"Vvedite imya ili stop: "<<endl;
               string name;
               cin>>name;
               if((name == "stop") || (name == "Stop") || (name == "STOP"))
                        break;
               for(int i=0; i<telBook.size(); i++)
               {
                       if(telBook[i].name ==name)
                       {
                             cout<<name<<" "<<telBook[i].number<<endl;             
                       }
               }
    }
}
