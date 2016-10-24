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
    int i=10, a[i], f, boof, boofch, boof2, boofiz, pr;
    bool d, boofzm;
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
    f=0;
    boofch=i*10;
    do
    {
        d,boofzm=false;
        for(int k=f; k<i; k++)
        {
                if(a[k]<a[k+1])
                {
                              // cout<<a[k]<<"<"<<a[k+1]<<endl;
                              boofzm=true;
                              if(a[k]<boofch)
                              {
                                            // cout<<a[k]<<"<"<<boofch<<endl;
                                             boof=boofch=a[k];
                                             boof2=k;
                                             // cout<<boof<<" boof и boofch "<<boofch<<endl;
                              }
                              else
                              {
                                 // cout<<a[k]<<">"<<boofch<<endl;
                                  boof=boofch;
                                  
                                  //cout<<boof<<" boof и boofch "<<boofch<<endl;
                              }
                }
                else
                {
                    //cout<<a[k]<<">"<<a[k+1]<<endl;
                    if(a[k]<boofch)
                    {
                                   d=true;
                    }
                }
        }
        //cout<<f+1<<" цикл вернул "<<boof<<" № "<<boof2+1<<endl;
        pr=boof;
        boofch=100;
        if(boofzm==true)
        {
            //cout<<"меняем местами "<<a[f]<<" & "<<a[boof2]<<endl;
            boofiz=a[f];
            a[f]=boof;
            a[boof2]=boofiz;
        }
        /*cout<<"Массив во время сортировки:"<<endl;
        for (int k=0; k<i; k++)
        {
            cout<<k+1<<ends<<a[k]<<endl;
        }*/
        pr=i;
        //cout<<"Проверка на конец сортировки."<<endl;
        for(int k=f; k<pr; k++)
        {
                if(a[k]<a[k+1])
                {
                              d=true;
                }
                else
                {
                   // cout<<"Сортировка не закончена."<<a[k]<<">"<<a[k+1]<<endl;
                                   d=false;
                                   pr=f;
                }
        }
        f++;
    }
    while(d!=true);
    cout<<"Массив после сортировки:"<<endl;
    for (int k=0; k<i; k++)
    {
        cout<<k+1<<ends<<a[k]<<endl;
    }
    getch();
}
