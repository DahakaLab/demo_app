#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream kl("ln16_1.txt");
    int n=100;
    int a[n];
    for(int q=0; q<n; q++)
    {
            
            a[q]=rand() %1000;
            a[q]=a[q]/10;
            cout<<a[q]<<endl;
            
            kl<<a[q]<<endl;
    }
    getch();
}
