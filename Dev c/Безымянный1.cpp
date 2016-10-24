#include <conio.h>
#include <iostream>
using std::cin;
using std::cout;

int main()
{
      int i,j;
      j=0;
      cout<<"vvedi massiv\n";
      cin>>i;
      int a[i];
      for(int zu=0;zu<i;zu++)
      {
              cout<<"vvedite dannye: "<<zu+1<<"\n";
              cin>>a[zu];
      }
      for(int moo=0;moo<i;moo++)
      {
      j=j+a[moo];
      }       
      cout<<"summa massiva: "<<j,"\n";
      getch();
}
      
