#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int main()
{
    /*ifstream f("ln16.txt");
    for(int i=0; i<10; i++)
    {
            int v;
            f>>v;
            cout<<v<<endl;
    }*/
    ofstream a("ln16_1.txt");
    for(int i=0; i<10; i++)
    {
            int v;
            cin>>v;
            a<<v<<endl;
    }
    ifstream f("ln16.txt");
    while(true)
    {
     {
                  int v;
                  f>>v;
                  if(!f.eof())
                              cout<<v<<endl;
                  else
                      break;
     }
    }
    getch();
}
