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
    int m, n, min, pr1, pr2, pr3, z, f=0;
    m=3; n=4;
    //m-склады, n-потребители.
    //b-склад, c-потребители
    int a[m][n], b[m], c[n];
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
    for(int i=0; i<m; i++)
    {
            for(int k=0; k<n; k++)
            {
                    cout<<ends<<a[i][k]<<"|";
            }
            cout<<ends<<b[i]<<endl;
    }
    cout<<endl<<ends;
    for(int i=0; i<n; i++)
    {
            cout<<c[i]<<"|";
    }
    cout<<endl;
    z=0;
    pr3=1;
    while(pr3)
    {
    for(int i=0; i<m; i++)
    {
            min=a[i][0];
            pr1=0;
            pr2=0;
            for(int k=0; k<n; k++)
            {
                    if(a[i][k]<min)
                    {
                                   min=a[i][k];
                                   pr1=k;
                                   pr2=i;
                    }
                    /*else
                    {
                        pr1=0;
                        pr2=i;
                    }
                    /*if(min==9)
                    cout<<i<<"min9 ";
                    else
                    cout<<i<<"vsok ";
                    if(i==2)
                    cout<<endl;*/
            }
            //b-склад, c-потребители
            if(c[pr1]<b[pr2])
            {
                             b[pr2]=b[pr2]-c[pr1];
                             z=z+(c[pr1]*a[pr2][pr1]);
                             c[pr1]=0;
            }
            else
            {
                if(b[pr2]!=0)
                {
                             z=z+(c[pr1]*a[pr2][pr1]);
                             c[pr1]=c[pr1]-b[pr2];
                             b[pr2]=0;
                }
            }
            if(c[pr1]==b[pr2])
            {
                          z=z+80;
                              c[pr1]=0;
                              b[pr2]=0;
            }
            if(c[pr1]==0)
            {
                         for(int k=0; k<m; k++)
                         {
                                 a[k][pr1]=9;
                         }
            }
            if(b[pr2]==0)
            {
                         for(int k=0; k<n; k++)
                         {
                                 a[pr2][k]=9;
                         }
            }
    }
    for(int i=0; i<n; i++)
    {
            if(c[i]!=0)
            f++;
    }
    if(f==0)
    {
            pr3=0;
    }
    else
    {
        f=0;
        int j=0;
        for(int k=0; k<20; k++)
        {
               j++; 
                if(j==20)
                pr3=0;
        }
    }
    }
    cout<<endl;
    for(int i=0; i<m; i++)
    {
            for(int k=0; k<n; k++)
            {
                    cout<<ends<<a[i][k]<<"|";
            }
            cout<<ends<<b[i]<<endl;
    }
    cout<<endl<<ends;
    for(int i=0; i<n; i++)
    {
            cout<<c[i]<<"|";
    }
    cout<<endl<<min<<ends<<pr1<<ends<<pr2;
    cout<<endl<<"Затраты: "<<z<<endl;
    system("pause");
}
