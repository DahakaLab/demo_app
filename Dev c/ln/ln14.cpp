#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int M=24;
    int W=78;
    char a[M][W];
    for(int y=0; y<M; y++)
    {
            for(int x=0; x<W; x++)
            a[y][x]='.';
    }
    for(int x=0; x<W; x++)
    {
            int y= x*x*M/(W*W);
            if((y<M) && (x<W))
            a[y][x]='*';
    }
    for(int y=0; y<M; y++)
    {
            for(int x=0; x<W; x++)
            cout<<a[y][x];
            cout<<endl;
    }
    getch();
}
