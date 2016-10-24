#include <iostream>

using namespace std;

int main()
{
    cout<<"Dahaka_inc"<<endl<<endl<<endl;
    float x,y,g;
    char z,d;
    do
    {
          cout<<"Primer: x+y "<<endl<<endl;
          cin>>x;
          cin>>z;
          cin>>y;
          switch(z)
          {
                   case '+':
                        g=x+y;
                   break;
                   case '-':
                        g=x-y;
                   break;
                   case '/':
                        g=x/y;
                   break;
                   case '*':
                        g=x*y;
                   break;
          }
          cout<<x<<z<<y<<"="<<g<<endl<<endl;
          cout<<"Esco nnnada?      (a-aga, n-nea)"<<endl;
          cin>>d;
    }
    while(d == 'a');
}
