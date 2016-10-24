#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

float f(float x)
{
      while (true)
      {
            char c;
            cout<<(int)x<<" Pravilno?  (+/-/=)"<<endl;
            cin>>c;
            switch (c)
            {
                   case '+':return +1;
                   case '-':return -1;
                   case '=':return 0;
            }
            cout<<"Chto? Davai eshe raz..."<<endl;
      }
}

float n(float x1, float x2)
{
      bool done;
      float x=(x1+x2)/2;
      float y=f(x);
      do
      {
            while (abs(y)>0.001)
            {
                  if (y>0)
                  x1=x;
                  else
                  x2=x;
                  x=(x1+x2)/2;
                  y=f(x);
            }
      }while (done);
      return x;
}

int main()
{
    cout<<"Dahaka_inc"<<endl<<endl<<endl;
    cout<<"Tvoe chislo "<<(int)n(0,100);
    getch();
}
