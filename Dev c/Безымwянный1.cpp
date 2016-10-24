#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int sum(int x)
{
    if (x<0)
    {
            x=x*-1;
    }
    if ((x>0) & (x<10))
    {
              return x;
              
    }
    else
    {
    if ((x>=10) & (x<100))
    {
             int c,v;
             c = x %10;
             v = x/10;
             x = c+v;
    }
    if ((x>=100) & (x<1000))
    {
              int c,v,b;
              b = x %100;
              b = b/10;
              c = x %10;
              v = x/100;
              x = c+v+b;
    }
    if ((x>=1000) & (x<10000))
    {
                  int c,v,b,n;
                  c=x/1000;
                  v=x%1000;
                  v=v/100;
                  b=x%100;
                  b=b/10;
                  n=x%10;
                  x=c+v+b+n;
                  return x;
    }
    else
    {
        string x;
        x = "Neverno zadano chislo, sboi v programme! ";
        cout<<x;
        
    }
    }
}

int main()
{
    int x;
    cout<<"Vvedite chislo ot 10 do 10000: ";
    cin>>x;
    cout<<sum(x)<<endl;
    getch();
}
