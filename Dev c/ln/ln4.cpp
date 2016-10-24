#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    cout<<"vvedi kolvo nog"<<endl;
    int g,o;
    cin>>g;
    o= g%100;
    if ((o>10) && (o<20))
    {
               cout<<"u menya "<<g<<" nog";
    }
    else
    {
        switch(o%10)
        {
                   case 0:
                        cout<<"u menya "<<g<<" nog";
                   break;
                   case 1:
                        cout<<"u menya "<<g<<" noga";
                   break;
                   case 2:
                   case 3:
                   case 4:
                        cout<<"u menya "<<g<<" nogi";
                   break;
                   case 5:
                   case 6:
                   case 7:
                   case 8:
                   case 9:
                        cout<<"u menya "<<g<<" nog";
                   break;
        }
    }
    getch();
}
