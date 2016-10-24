#include <iostream>
#include <conio.h>

using namespace std;

int ch(int k)
{
    int p,g,pr;
    pr=1;
    for(int i=2; i<10; i++)
    {
            g=k/i;
            g=g*i;
            if(g!=k)
            pr+=1;
    }
    if(k==1)
    {p=k;}
    if(k<=9)
    {
           if(pr==8)
           p=k;
    }
    if(k>9)
    {
           if(pr==9)
           p=k;
    }
    return p;
}

int main()
{
    int n,k;
    k=1;
    cout<<"Vvedite n:"<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
            if((ch(k)>0)&(ch(k)<n))
            cout<<ch(k)<<endl;
            k+=1;
    }
    getch();
}
