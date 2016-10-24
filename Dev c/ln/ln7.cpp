#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

float dist(float v, float a)
{
      return v*v*sin(2*a*M_PI/180)/9.81;
}
      
int main()
{
    float v,d,max_d,max_a,y;
    max_d=0;
    cout<<"Vvedi skorost'"<<endl;
    cin>>v;
    for(float a=0; a<90; a++)
    {
            d=dist(v,a);
            if(d>max_d)
            {
                     max_d=d;
                     max_a=a;
            }
    }
    cout<<"Maximal'noe rasstoyanie: "<<max_d<<endl<<"Pri ygle ravnom "<<max_a<<"*"<<endl;
    float a;
    cout<<"Vvedi ugol"<<endl;
    cin>>a;
    d=dist(v,a);
    cout<<"Rasstoyanie budet: "<<d<<endl;
    getch();
}
