#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

float h(float p, float q)
{
            float h,k1,k2,gi,x,y;
            k1=p/2;
            k2=q/2;
            x=(k1*k1)+(k2+k2);
            gi=sqrt(x);
            x=(k1+k2+gi)/2;
            y=x*(x-k1)*(x-k2)*(x-gi);
            y=(2*sqrt(y))/gi;
            return y;
}

int main()
{
    float p,q,r,x;
    cout<<"Lab 2 zadacha 3\nVvedite dioganal romba p: "<<endl;
    cin>>p;
    cout<<"Vvedite dioganal romba q: "<<endl;
    cin>>q;
    cout<<"Vvedite radiys kryga : "<<endl;
    cin>>r;
    cout<<"Radiys vpisannogo kryga v romb budet: "<<h(p,q)<<endl;
    if(r<h(p,q))
    {
           cout<<"Kruk s radiysom "<<r<<" proidet";
    }
    else
    {
        cout<<"Kruk s radiysom "<<r<<" ne proidet";
    }
    getch();
}
