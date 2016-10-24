#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>

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
    system("Color 12");
    char c, prv;
    int a, p=1, cp, autos=0;
    SetColor((ConsoleColor)11,(ConsoleColor)1);
    cout<<"���� ������ �����, � ��������� ����� �� 0 �� 100,\n� ������ �� ������� ������ ��� ���������."<<endl;
    SetColor((ConsoleColor)12,(ConsoleColor)1);
    cout<<"�������� ����� ����? (y-��)"<<endl;
    SetColor((ConsoleColor)10,(ConsoleColor)1);
    cin>>c;
    srand(time(0));
    int ch=rand()%100;
    if(c=='y')
    {
              SetColor((ConsoleColor)12,(ConsoleColor)1);
              cout<<"������� ���������� ������� �� 1 �� 10:"<<endl;
              SetColor((ConsoleColor)10,(ConsoleColor)1);
              cin>>a;
              do
              {
                     if((a<1) or (a>10))
                     {
                              SetColor((ConsoleColor)12,(ConsoleColor)1);
                              cout<<"������������ ����� �������, ��������� ��� �����..."<<endl;
                              SetColor((ConsoleColor)10,(ConsoleColor)1);
                              cin>>a;
                              if((a<1) or (a>10))
                              {
                                       SetColor((ConsoleColor)11,(ConsoleColor)1);
                                       cout<<"�� �����!>_<"<<endl;
                              }
                     }
                     else
                     prv='v';
              }while(prv!='v');
              prv='@';
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
              save<<p;
    }
    c='@';
    ifstream save("system01.dah");
    save>>a;
    int s[a];
    for(int i=1; i<(a+1); i++)
    {
            save>>s[i-1];
    }
    save>>p;
    SetColor((ConsoleColor)14,(ConsoleColor)1);
    cout<<"���������� �������: "<<a<<endl;
    for(int i=0; i<a; i++)
    {
            switch(s[i]%10)
            {
                           case 0:
                                cout<<"����� "<<i+1<<" ��������� "<<s[i]<<" �����"<<endl;
                                break;
                           case 1:
                                cout<<"����� "<<i+1<<" ��������� "<<s[i]<<" ������"<<endl;
                                break;
                           case 2:
                           case 3:
                           case 4:
                                cout<<"����� "<<i+1<<" ��������� "<<s[i]<<" ������"<<endl;
                                break;
                           case 5:
                           case 6:
                           case 7:
                           case 8:
                           case 9:
                                cout<<"����� "<<i+1<<" ��������� "<<s[i]<<" �����"<<endl;
                                break;
            }
    }
    SetColor((ConsoleColor)11,(ConsoleColor)1);
    cout<<"����� ����� ��� ������� "<<p<<endl;
    SetColor((ConsoleColor)12,(ConsoleColor)1);
    cout<<"������ ��������� �������:"<<endl;
    SetColor((ConsoleColor)15,(ConsoleColor)1);
    cout<<"666 - ��������� � �����\n132 - ������� � ����."<<endl;
    SetColor((ConsoleColor)11,(ConsoleColor)1);
    cout<<"� ������� �����, ���������� ��� ��������!"<<endl;
    do
    {
        SetColor((ConsoleColor)14,(ConsoleColor)1);
        cout<<"����� "<<p<<" ������� �����:"<<endl;
        SetColor((ConsoleColor)10,(ConsoleColor)1);
        cin>>cp;
        if(cp==301092)
        {
                      SetColor((ConsoleColor)9,(ConsoleColor)1);
                      cout<<ch<<endl;
                      SetColor((ConsoleColor)7,(ConsoleColor)1);
                      cin>>cp;
        }
        if(cp==132)
        {
                   SetColor((ConsoleColor)12,(ConsoleColor)1);
                   cout<<"������ ��������� �������:"<<endl;
                   SetColor((ConsoleColor)15,(ConsoleColor)1);
                   cout<<"s - ��������� ��������� � ����������\nn - �����\no - ��������� � �����"<<endl;
                   cout<<"y - ����� ����\np - ����������."<<endl; 
                   SetColor((ConsoleColor)14,(ConsoleColor)1);
                   cout<<"���� �����:"<<endl;
                   SetColor((ConsoleColor)10,(ConsoleColor)1);
                   cin>>c;
                   if((c=='p') or (c=='s'))
                   {
                             SetColor((ConsoleColor)14,(ConsoleColor)1);
                             cout<<"����������, ����� "<<p<<" ������� �����"<<endl;
                             SetColor((ConsoleColor)10,(ConsoleColor)1);
                             cin>>cp;
                   }
        }
        if((cp!=132) or (c=='p') or (c=='s'))
        {if(cp<ch)
        {
                 SetColor((ConsoleColor)14,(ConsoleColor)1);
                 cout<<"��� ������"<<endl;
        }
        if(cp>ch)
        {
                 SetColor((ConsoleColor)14,(ConsoleColor)1);
                 cout<<"��� ������"<<endl;
        }
        if(cp==ch)
        {
                  ch=rand()%100;
                  SetColor((ConsoleColor)14,(ConsoleColor)1);
                  cout<<"����� "<<p<<" ������ � �������� 1 ������."<<endl;
                  s[p-1]++;
                  for(int i=0; i<a; i++)
                  {
                          switch(s[i]%10)
                          {
                                      case 0:
                                      case 1:
                                                     cout<<"����� "<<i+1<<" ������� "<<s[i]<<" ���"<<endl;
                                                     break;
                                      case 2:
                                      case 3:
                                      case 4:
                                                     cout<<"����� "<<i+1<<" ������� "<<s[i]<<" ����"<<endl;
                                                     break;
                                      case 5:
                                      case 6:
                                      case 7:
                                      case 8:
                                      case 9:
                                                     cout<<"����� "<<i+1<<" ������� "<<s[i]<<" ���"<<endl;
                                                     break;
                          }
                  }
                  SetColor((ConsoleColor)12,(ConsoleColor)1);
                  cout<<"������ ��������� �������:"<<endl;
                  SetColor((ConsoleColor)15,(ConsoleColor)1);
                  cout<<"s - ��������� ��������� � ����������\nn - �����\no - ��������� � �����"<<endl;
                  cout<<"y - ����� ����."<<endl;          
                  SetColor((ConsoleColor)10,(ConsoleColor)1);
                  cin>>c;
        }}
        if(cp==666)
        {
                   c='o';
                   p--;
        }
        if(autos>10)
        {
                     c='s';
                     autos=0;
                     SetColor((ConsoleColor)12,(ConsoleColor)1);
                     cout<<"���� ����������..."<<endl;
        }
        if(c=='y')
        {
                  ch=rand()%100;
                  SetColor((ConsoleColor)12,(ConsoleColor)1);
                  cout<<"������� ����� ���������� �������"<<endl;
                  SetColor((ConsoleColor)10,(ConsoleColor)1);
                  cin>>a;
                  do
                  {
                         if((a<1) or (a>10))
                         {
                                  SetColor((ConsoleColor)12,(ConsoleColor)1);
                                  cout<<"������������ ����� �������, ��������� ��� �����..."<<endl;
                                  SetColor((ConsoleColor)10,(ConsoleColor)1);
                                  cin>>a;
                                  if((a<1) or (a>10))
                                  {
                                           SetColor((ConsoleColor)11,(ConsoleColor)1);
                                           cout<<"�� �����!>_<"<<endl;
                                  }
                         }
                         else
                         prv='v';
                  }while(prv!='v');
                  for(int i=0; i<a;i++)
                  {
                          s[i]=0;
                  }
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
                  p=1;
                  save<<p;
                  SetColor((ConsoleColor)12,(ConsoleColor)1);
                  cout<<"���������!"<<endl;
                  SetColor((ConsoleColor)14,(ConsoleColor)1);
                  cout<<"���������� �������: "<<a<<endl;
                  for(int i=0; i<a; i++)
                  {
                          cout<<"����� "<<i+1<<" �������� ������ "<<endl;
                  }
                  SetColor((ConsoleColor)11,(ConsoleColor)1);
                  cout<<"����� ����� ��� ������� "<<p<<endl;
                  SetColor((ConsoleColor)12,(ConsoleColor)1);
                  p=0;
                  c='@';
        }
        if(c=='s')
        {
                  ofstream changesave("system01.dah");
                  changesave<<a<<endl;
                  for(int i=1; i<(a+1); i++)
                  {
                          changesave<<s[i-1]<<endl;
                  }
                  SetColor((ConsoleColor)12,(ConsoleColor)1);
                  cout<<"���������!"<<endl;
                  changesave<<p;
                  c='@';
        }
        if(c=='o')
        {
                  ofstream changesave("system01.dah");
                  changesave<<a<<endl;
                  for(int i=1; i<(a+1); i++)
                  {
                          changesave<<s[i-1]<<endl;
                  }
                  SetColor((ConsoleColor)12,(ConsoleColor)1);
                  cout<<"���������!"<<endl;
                  p++;
                  if(p>a)
                  p=1;
                  changesave<<p;
                  c='n';
        }
        autos++;
        p++;
        if(p>a)
        {
                    p=1;
        }
    }while(c!='n');
}
