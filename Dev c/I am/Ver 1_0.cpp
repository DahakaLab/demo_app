#include <iostream>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>

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
    system("Color D2");
    int x,y,p,t,pp;
    char c,b;
    c=' ';
    b='A';
    x=7;
    y=79;
    char a[x][y];
    pp=0;
    while(pp!=1)
    {
    for(int i=0; i<x; i++)
    {
            for(int k=0; k<y; k++)
            {
                    a[i][k]=c;
            }
    }
    a[1][1]=a[5][1]=a[5][2]=a[1][2]=a[1][3]=a[2][3]=a[3][3]=a[4][3]=a[5][3]='A';
    a[3][4]=a[3][5]=a[3][6]=a[3][7]=a[2][5]=a[1][5]=a[4][5]=a[5][5]=a[4][7]='Û';
    a[5][7]=a[5][8]=a[2][7]=a[1][7]=a[1][8]=a[1][9]=a[5][9]=a[1][11]=a[1][12]='C';
    a[1][13]=a[1][14]=a[1][15]=a[2][11]=a[3][11]=a[4][11]=a[5][11]=a[5][12]=a[5][13]='D';
    a[5][14]=a[5][15]=a[3][12]=a[3][13]=a[4][17]=a[1][17]=a[2][17]=a[3][17]=a[5][17]='E';
    a[3][18]=a[3][19]=a[3][20]=a[1][20]=a[2][20]=a[4][20]=a[5][20]=a[2][22]=a[5][22]='Û';
    a[1][23]=a[1][24]=a[1][25]=a[3][23]=a[3][24]=a[3][25]=a[4][23]=a[1][26]=a[2][26]='Û';
    a[3][26]=a[4][26]=a[5][26]='Û';
    for(int i=0; i<x; i++)
    {
            cout<<endl;
            for(int k=0; k<y; k++)
            {
                    SetColor((ConsoleColor)12,(ConsoleColor)10);
                    cout<<a[i][k];
            }
    }
    for(int i=0; i<x; i++)
    {
            for(int k=0; k<y; k++)
            {
                    a[i][k]=c;
            }
    }
    a[1][28]=a[2][28]=a[3][28]=a[4][28]=a[5][28]=a[1][29]='I';
    a[1][30]=a[1][31]=a[1][33]=a[3][35]=a[2][33]=a[3][36]=a[3][37]=a[2][37]=a[1][37]='J';
    a[4][37]=a[5][36]=a[5][36]=a[5][35]=a[5][34]=a[5][33]=a[3][34]=a[2][39]=a[3][39]='K';
    a[4][39]=a[5][40]=a[1][40]=a[1][41]=a[5][41]=a[5][42]=a[1][42]=a[1][43]=a[5][43]='L';
    a[1][45]=a[2][45]=a[3][45]=a[4][45]=a[5][45]=a[3][46]=a[3][47]=a[3][48]=a[4][49]='M';
    a[5][48]=a[5][47]=a[5][46]='N';
    for(int i=0; i<x; i++)
    {
            
            cout<<endl;
            for(int k=0; k<y; k++)
            {
                    if((k<27)or(k>50))
                                      SetColor((ConsoleColor)12,(ConsoleColor)k);
                    else
                        SetColor((ConsoleColor)12,(ConsoleColor)15);
                    cout<<a[i][k];
            }
    }
    for(int i=0; i<x; i++)
    {
            for(int k=0; k<y; k++)
            {
                    a[i][k]=c;
            }
    }
    a[1][28]=a[2][28]=a[3][28]=a[4][28]=a[5][28]=a[1][29]='O';
    a[1][30]=a[1][31]=a[1][33]=a[3][35]=a[2][33]=a[3][36]=a[3][37]=a[2][37]=a[1][37]='Û';
    a[4][37]=a[5][36]=a[5][36]=a[5][35]=a[5][34]=a[5][33]=a[3][34]=a[2][39]=a[3][39]='Û';
    a[4][39]=a[5][40]=a[1][40]=a[1][41]=a[5][41]=a[5][42]=a[1][42]=a[1][43]=a[5][43]='Û';
    a[1][45]=a[2][45]=a[3][45]=a[4][45]=a[5][45]=a[3][46]=a[3][47]=a[3][48]=a[4][49]='Û';
    a[5][48]=a[5][47]=a[5][46]='T';
    for(int i=0; i<x; i++)
    {
            
            cout<<endl;
            for(int k=0; k<y; k++)
            {
                    SetColor((ConsoleColor)12,(ConsoleColor)11);
                    cout<<a[i][k];
            }
    }
    SetColor((ConsoleColor)1,(ConsoleColor)13);
    cout<<endl<<"ÑÏÀÑÈÁÎ ÃÓÔÓ ÇÀ ÝÒÎ!!!\nG-ãóðäà"<<endl;
    SetColor((ConsoleColor)0,(ConsoleColor)13);

    system("PAUSE");
}}
