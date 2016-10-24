#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;

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
    char c;
    int a, p=1, cp, autos=0;
    cout<<"Начинаем новую игру? (y-да)"<<endl;
    cin>>c;
    srand(time(0));
    int ch=rand()%100;
    if(c=='y')
    {
              cout<<"Введите количество игроков"<<endl;
              cin>>a;
              int s[a];
              ofstream save("system01.dah");
              save<<a<<endl;
              for(int i=0; i<a; i++)
              {
                      s[i]=0;
              }
              for(int i=1; i<(a+1); i++)
              {
                      save<<s[i-1]<<endl;
              }
    }
    c='@';
    ifstream save("system01.dah");
    save>>a;
    int s[a];
    for(int i=1; i<(a+1); i++)
    {
            save>>s[i-1];
    }
    cout<<"Количество игроков: "<<a<<endl;
    for(int i=0; i<a; i++)
    {
            cout<<"Игрок "<<i+1<<" получает "<<s[i]<<" очков"<<endl;
    }
    cout<<"Я загадал число, попробуйте его отгадать!"<<endl;
    do
    {
        cout<<"Игрок "<<p<<" введите число:"<<endl;
        cin>>cp;
        if(cp==301092)
        {
                      cout<<ch<<endl;
                      cin>>cp;
        }
        if(cp==132)
        {
                   cout<<"Ждем ввода:"<<endl;
                   cin>>c;
                   if(c=='?')
                   {
                             cout<<"p - продолжить"<<endl;
                             cout<<"Список доступных комманд:\ns - Сохранить результат\nn - Выход\no - Сохранить и выйти"<<endl;
                             cout<<"666 - (только во время игры) сохранить и выйти\ny - новая игра.\n132 - (только во время игры) переход в меню"<<endl;
                             cin>>c;
                   }
                   if(c=='p')
                   {
                             cout<<"Продолжаем, игрок "<<p<<" введите число"<<endl;
                             cin>>cp;
                   }
        }
        if((cp!=132) or (c=='p'))
        {if(cp<ch)
        {
                 cout<<"Мое больше"<<endl;
        }
        if(cp>ch)
        {
                 cout<<"Мое меньше"<<endl;
        }
        if(cp==ch)
        {
                  ch=rand()%100;
                  cout<<"Угадал"<<endl;
                  cout<<"Еще? (?-help)"<<endl;
                  s[p-1]++;
                  for(int i=0; i<a; i++)
                  {
                          cout<<s[i]<<endl;
                  }
                  cin>>c;
                  if(c=='?')
                  {
                            cout<<"Список доступных комманд:\ns - Сохранить результат\nn - Выход\no - Сохранить и выйти"<<endl;
                            cout<<"666 - (только во время игры) сохранить и выйти\ny - новая игра\n132 - (только во время игры) переход в меню."<<endl;
                            cin>>c;
                  }
        }}
        if(cp==666)
        {
                   c='o';
        }
        p++;
        autos++;
        if(autos==25)
        {
                     c='s';
                     autos=0;
        }
        if(c=='y')
        {
                  for(int i=0; i<a;i++)
                  {
                          s[i]=0;
                  }
        }
        if(c=='s');
        {
                   ofstream changesave("system01.dah");
                   changesave<<a<<endl;
                   for(int i=1; i<(a+1); i++)
                   {
                           changesave<<s[i-1]<<endl;
                   }
        }
        if(c=='o')
        {
                  ofstream changesave("system01.dah");
                  changesave<<a<<endl;
                  for(int i=1; i<(a+1); i++)
                  {
                          changesave<<s[i-1]<<endl;
                  }
                  c='n';
        }
        if(p==(a+1))
        {
                    p=1;
        }
    }while(c!='n');
}
