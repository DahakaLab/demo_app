#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int main()
{
    int n=5;
    int a[n];
    ifstream f("ln16.txt");
    for(int i=0; i<n; ++i)
    {
            f>>a[n];
            cout<<a[n];
    }
    for(int i=n-1; i>=1; i--)
            for(int j=0; j<1; j++)
            {
                    if(a[j]>a[j+1])
                    {
                                    int foo = a[j];
                                    a[j]=a[j+1];
                                    a[j+1]=foo;
                    }
            }
    
    cout<<endl;
    for(int i=0; i<n; i++)
    {
            cout<<a[n];
    }
    getch();
}
