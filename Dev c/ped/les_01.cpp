#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

enum ConsoleColor 
{ 
 Black = 0, 
 Blue = 1, 
 Green = 2, 
 Cyan = 3, 
 Red = 4, 
 Magenta = 5, 
 Brown = 6, 
 LightGray = 7, 
 DarkGray = 8, 
 LightBlue = 9, 
 LightGreen = 10, 
 LightCyan = 11, 
 LightRed = 12, 
 LightMagenta = 13, 
 Yellow = 14, 
 White = 15 
};

void SetColor(ConsoleColor text, ConsoleColor background) 
{ 
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
 SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text)); 
}

ostream& operator<<(ostream& out, const char* str)
{
    char buf[100];
    if(CharToOem(str, buf))
    {
        for(int i = 0; str[i] != 0; i++)
            out << buf[i];
    }
    return out;
}

int main()
{
    int i=10, a[i];
    bool d;
    srand(time(0));
    for(int k=0; k<i; k++)
    {
        a[k]=rand()%100;
    }
    cout<<"Массив введен:"<<endl;
    for (int k=0; k<i; k++)
    {
        cout<<k+1<<ends<<a[k]<<endl;
    }
    do
    {
      d=false;
      for(int k=0; k<i; k++)
      {
               int l;
               if (a[k]>a[k+1])
               {
                            l=a[k];
                            a[k]=a[k+1];
                            a[k+1]=l;
                            d=true;
                }
      }
    }
    while(d!=false);
    cout<<"Массив после:"<<endl;
    for (int k=0; k<i; k++)
    {
        cout<<k+1<<ends<<a[k]<<endl;
    }
    getch();
}
