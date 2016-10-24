#include <iostream>
#include <conio.h>

using namespace std;

int ch(int k)
{
    int p,g,m,z;
    g=k/2;
    g=g*2;
    if(g!=k)
    {
            z=k/10;
            m=z%2;
            if(m==0)
            p=k;
    }
    return p;
}

int main()
{
    int n,k,pr,;
    n=100;
    k=pr=1;
    n++;
    while(pr<n)
    {
                if((ch(k)>9)&(ch(k)<n))
                cout<<ch(k)<<endl;
                k++;
                pr++;
    }
    getch();
}
