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
    cout<<"�������� ����� ����? (y-��)"<<endl;
    cin>>c;
    srand(time(0));
    int ch=rand()%100;
    if(c=='y')
    {
              cout<<"������� ���������� �������"<<endl;
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
    cout<<"���������� �������: "<<a<<endl;
    for(int i=0; i<a; i++)
    {
            cout<<"����� "<<i+1<<" �������� "<<s[i]<<" �����"<<endl;
    }
    cout<<"� ������� �����, ���������� ��� ��������!"<<endl;
    do
    {
        cout<<"����� "<<p<<" ������� �����:"<<endl;
        cin>>cp;
        if(cp==301092)
        {
                      cout<<ch<<endl;
                      cin>>cp;
        }
        if(cp==132)
        {
                   cout<<"���� �����:"<<endl;
                   cin>>c;
                   if(c=='?')
                   {
                             cout<<"p - ����������"<<endl;
                             cout<<"������ ��������� �������:\ns - ��������� ���������\nn - �����\no - ��������� � �����"<<endl;
                             cout<<"666 - (������ �� ����� ����) ��������� � �����\ny - ����� ����.\n132 - (������ �� ����� ����) ������� � ����"<<endl;
                             cin>>c;
                   }
                   if(c=='p')
                   {
                             cout<<"����������, ����� "<<p<<" ������� �����"<<endl;
                             cin>>cp;
                   }
        }
        if((cp!=132) or (c=='p'))
        {if(cp<ch)
        {
                 cout<<"��� ������"<<endl;
        }
        if(cp>ch)
        {
                 cout<<"��� ������"<<endl;
        }
        if(cp==ch)
        {
                  ch=rand()%100;
                  cout<<"������"<<endl;
                  cout<<"���? (?-help)"<<endl;
                  s[p-1]++;
                  for(int i=0; i<a; i++)
                  {
                          cout<<s[i]<<endl;
                  }
                  cin>>c;
                  if(c=='?')
                  {
                            cout<<"������ ��������� �������:\ns - ��������� ���������\nn - �����\no - ��������� � �����"<<endl;
                            cout<<"666 - (������ �� ����� ����) ��������� � �����\ny - ����� ����\n132 - (������ �� ����� ����) ������� � ����."<<endl;
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
