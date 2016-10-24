#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

main()
{
      int n=10;
      int a[n];
      ifstream f("ln16.txt");
      for(int i=0; i<n; i++)
      {
              f>>a[i];
              cout<<a[i];
      }
      for(int i=n-1; i>=0; i--)
      {
              for(int j=0;j<i;j++)
              {
                      if(a[j]>a[j+1])
                      {
                                     int foo = a[j];
                                     a[j] = a[j+1];
                                     a[j+1] = foo;
                      }
              }
      }
      cout<<endl;
      for(int i=0; i<n; i++)
      {
              cout<<a[i];
      }
      getch();
}
