#include <iostream>
#include <windows.h>
#include <math.h>
#include <stdio.h>

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

float P1(float a1, float a2, float a3)
{
      float P1R;
      P1R=((4/5)+((a1*a2)/a3)+(a1/(a2*a3)))/100;
      return P1R;
}

float R1(float a1, float a2, float a3, float m, float n)
{
      float R1R;
      R1R=(m*n)+(m/(a1+a2))+(n/(a2+a3));
      return R1R;
}

float S1(float a1, float a2, float a3, float m, float n)
{
      float S1R;
      S1R=((2/a1)+(2/a2)+(2/a3))*((a1*m)/(a2*n));
      return S1R;
}

//-----------

float P2(float a, float b, float g1, float g2)
{
      float P2R;
      P2R=(1000)/(g1*g2)+(1/(a+b));
      return P2R;
}

float R2(float a, float b, float c)
{
      float R2R;
      R2R=((a*b)/c)+(b/(a*c));
      return R2R;
}

float T2(float a, float b, float c)
{
      float T2R;
      T2R=((a+b)/(c+b))+(a+(b/c))/(c+(a/b));
      return T2R;
}

//-----------

float J(float a31, float b3, float c3)
{
      float JR;
      JR=(((a31*b3)/100)+((2*a31))/((b3*c3))+((3*b3*c3)/a31));
      return JR;
}

float K(float a31, float b3, float c3, float alpha, float beta)
{
      float KR;
      KR=((a31+b3)/10000)*((2/a31)+(alpha/b3)-(c3/(b3*beta)));
      return KR;
}

float L(float a31, float b3, float c3, float alpha, float beta)
{
      float LR;
      LR=((a31*b3*c3)/(1+alpha))+((a31*b3*c3)/(1+beta))+(1/5);
      return LR;
}

int main(int argc, char *argv[])
{
    cout<<"Лаб 1"<<endl<<endl<<"Задача 3"<<endl
               <<"Введите целые числа: "<<endl;
    int a1, a2, a3;
    float m, n;
    cin>>a1>>a2>>a3;
    cout<<"Введите вещественные: "<<endl;
    cin>>m>>n;
    SetColor((ConsoleColor)15,(ConsoleColor)0);
    printf("P=%8.5f\n",P1(a1,a2,a3));
    SetColor((ConsoleColor)9,(ConsoleColor)0);
    printf("R=%8.5f\n",R1(a1,a2,a3,m,n));
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    printf("S=%8.5f\n",S1(a1,a2,a3,m,n));
    SetColor((ConsoleColor)7,(ConsoleColor)0);
    cout<<endl;
//-------------------
    cout<<"Задача 10"<<endl;
    int a,b,c;
    float g1,g2;
    cout<<"Введите целые числа: "<<endl;
    cin>>a>>b>>c;
    cout<<"Введите вещественные: "<<endl;
    cin>>g1>>g2;
    SetColor((ConsoleColor)14,(ConsoleColor)0);
    printf("P=%8.4f\n",P2(a,b,g1,g2));
    SetColor((ConsoleColor)8,(ConsoleColor)0);
    printf("R=%8.4f\n",R2(a,b,c));
    SetColor((ConsoleColor)13,(ConsoleColor)0);
    printf("T%8.4f\n",T2(a,b,c));
    SetColor((ConsoleColor)7,(ConsoleColor)0);
    cout<<endl;
//-------------------
    cout<<"Задача 17"<<endl;
    int a31,b3,c3;
    float alpha,beta;
    cout<<"Введите целые числа: "<<endl;
    cin>>a31>>b3>>c3;
    cout<<"Введите вещественные: "<<endl;
    cin>>alpha>>beta;
    SetColor((ConsoleColor)5,(ConsoleColor)0);
    printf("J=%8.6f\n",J(a31,b3,c3));
    SetColor((ConsoleColor)8,(ConsoleColor)0);
    printf("K=%8.6f\n",K(a31,b3,c3,alpha,beta));
    SetColor((ConsoleColor)2,(ConsoleColor)0);
    printf("L=%8.6f\n",L(a31,b3,c3,alpha,beta));
    SetColor((ConsoleColor)7,(ConsoleColor)0);
    system("PAUSE");
}
