#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>

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

int main(int argc, char *argv[])
{
    bool done;
    char c;
    int plp, pl=0;
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    cout<<"Игра угадай число.\nКомпьютер загадывает число и игроки по очереди должны угадывать.\nПобедителю начисляется 1 очко."<<endl;
    cout<<"Введите количество игроков"<<endl;
    cin>>plp;
    int ind=plp-1;
    int sc[ind];
    srand(time(0));
    int ch=rand()%100;
    for(int i=0; i<plp; i++)
    {
            sc[i]=0;
    }
    while(done)
    {
               int x;
               char f;
               cout<<pl+1<<" игрок ведите число"<<endl;
               cin>>x;
               if(x==132)
               {
                         f='c';
               }
               if(x<ch)
               {
                       cout<<"Мое число больше"<<endl;
               }
               if(x>ch)
               {
                   cout<<"Мое число меньше"<<endl;
               }
               if(x==ch)
               {
                        cout<<"Число угадано, ждем ввода:  (?-help)"<<endl;
                        sc[pl]++;
                        for(int i=0; i<plp; i++)
                        {
                                cout<<"Игрок "<<i+1<<" получил "<<sc[i]<<" очков."<<endl;
                        }
                        cin>>f;
                        if(f=='?')
                        {
                                cout<<"n - выход\nНу и что мы будем делать?"<<endl;
                                cin>>f;
                        }
                        cin>>f;
               }
               switch (f)
               {
                      case 'n':
                           c='n';
                           break;
               }
               pl++;
               if(pl==plp)
               {
                         pl=0;
               }
               done=(c!='n');
    }
}
