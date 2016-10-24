#include <iostream>
#include <windows.h>

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
    int m, n, min, pr1, pr2, pr3, z=0, k=0;
    m=3; n=4;
    //m-склады, n-потребители.
    //b-склад, c-потребители
    int a[m][n], b[m], c[n], af[m][n], zer[m][n];
    a[0][0]=5;
    a[0][1]=6;
    a[0][2]=1;
    a[0][3]=2;
    a[1][0]=3;
    a[1][1]=1;
    a[1][2]=8;
    a[1][3]=7;
    a[2][0]=8;
    a[2][1]=1;
    a[2][2]=2;
    a[2][3]=7;
    b[0]=15;
    b[1]=15;
    b[2]=20;
    c[0]=10;
    c[1]=20;
    c[2]=8;
    c[3]=12;
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    cout<<"–ешите транспортную матрицу: "<<endl;
    SetColor((ConsoleColor)10,(ConsoleColor)0);
    for(int i=0; i<m; i++)
    {
            for(int k=0; k<n; k++)
            {
                    cout<<ends<<a[i][k]<<"|";
            }
            cout<<ends<<b[i]<<endl;
    }
    cout<<endl<<ends;
    for(int i=0; i<m; i++)
    {
            for(int k=0; k<n; k++)
            {
                    af[i][k]=a[i][k];
                    zer[i][k]=0;
            }
    }
    for(int i=0; i<n; i++)
    {
            cout<<c[i]<<"|";
    }
    int j=0;
    while(pr3)
    {
              //b,m-склад, c,n-потребители
              min=9999;
              pr1=0;
              pr2=0;
              for(int i=0; i<m; i++)
              {
                      for(int k=0; k<n; k++)
                      {
                              if(a[i][k]<min)
                              {
                                             min=a[i][k];
                                             pr1=i;
                                             pr2=k;
                              }
                      }
              }
              if(min<9999)
              {
                       //b,pr1,m-склад, c,pr2,n-потребители
                       if(c[pr2]<b[pr1])
                       {
                                      zer[pr1][pr2]=c[pr2];
                                      z=z+(c[pr2]*a[pr1][pr2]);
                                      b[pr1]=b[pr1]-c[pr2];
                                      c[pr2]=0;
                                      k++;
                       }
                       else
                       {
                           zer[pr1][pr2]=b[pr1];
                           z=z+(b[pr1]*a[pr1][pr2]);
                           c[pr2]=c[pr2]-b[pr1];
                           b[pr1]=0;
                           k++;
                       }
              }
              for(int i=0; i<n; i++)
              {
                      if(c[i]==0)
                      {
                                 for(int k=0; k<m; k++)
                                 {
                                         a[k][i]=9999;
                                 }
                      }
              }
              for(int i=0; i<m; i++)
              {
                      if(b[i]==0)
                      {
                                for(int k=0; k<n; k++)
                                {
                                        a[i][k]=9999;
                                }
                      }
              }
              for(int i=0; i<n; i++)
              {
                      if(c[i]!=0)
                      {
                                 j++;
                      }
              }
              if(j==0)
              {
                      pr3=0;
              }
              j=0;
    }
    for(int i=0; i<m; i++)
    {
            for(int k=0; k<n; k++)
            {
                    a[i][k]=af[i][k];
            }
    }
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    cout<<endl;
    cout<<"ѕервичный ответ: ";
    for(int i=0; i<m; i++)
    {
            SetColor((ConsoleColor)10,(ConsoleColor)0);
            cout<<endl;
            for(int k=0; k<n; k++)
            {
                    if((zer[i][k]<10)&(zer[i][k]>=0))
                    {
                                       SetColor((ConsoleColor)13,(ConsoleColor)0);
                                       cout<<"  "<<zer[i][k];
                                       SetColor((ConsoleColor)7,(ConsoleColor)0);
                                       cout<<"|";
                    }
                    if((zer[i][k]<0)&(zer[i][k]>-10))
                    {
                        SetColor((ConsoleColor)13,(ConsoleColor)0);
                        cout<<" "<<zer[i][k];
                        SetColor((ConsoleColor)7,(ConsoleColor)0);
                        cout<<"|";
                    }
                    if((zer[i][k]<100)&(zer[i][k]>=10))
                    {
                        SetColor((ConsoleColor)13,(ConsoleColor)0);
                        cout<<" "<<zer[i][k];
                        SetColor((ConsoleColor)7,(ConsoleColor)0);
                        cout<<"|";
                    }
                    if((zer[i][k]<=-10)&(zer[i][k]>-100))
                    {
                        SetColor((ConsoleColor)13,(ConsoleColor)0);
                        cout<<zer[i][k];
                        SetColor((ConsoleColor)7,(ConsoleColor)0);
                        cout<<"|";
                    }
            }
    }
    cout<<endl;
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    cout<<endl<<"«атраты: ";
    SetColor((ConsoleColor)10,(ConsoleColor)0);
    cout<<z<<ends;
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    cout<<"—колько базисных клеток: ";
    SetColor((ConsoleColor)10,(ConsoleColor)0);
    cout<<k<<endl;
    SetColor((ConsoleColor)7,(ConsoleColor)0);
    system("pause");
}
