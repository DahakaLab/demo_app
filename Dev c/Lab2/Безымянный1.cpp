#include <iostream>
#include <windows.h>
#include <ctime>
#include <math.h>

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
    cout<<"Каманин Н.Д. ТК-21"<<endl<<endl;
    srand(0);
    char c;
    int mat,ra;
    bool pr;
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    cout<<"Введите размерность квадратной матрицы"<<endl;
    SetColor((ConsoleColor)7,(ConsoleColor)0);
    cin>>mat;
    double matrix[mat][mat];
    double x[mat], b[mat], mau, sum=0;
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    cout<<"Заполняем в ручную? (y/n)"<<endl;
    SetColor((ConsoleColor)7,(ConsoleColor)0);
    cin>>c;
    system("cls");
    pr=(c!='y');
    if(pr)
    {
          for(int i=0; i<mat; i++)
          {          
                     for(int k=0; k<mat; k++)
                     {
                             ra=rand()%100;
                             if(ra<50)
                             {
                                      matrix[i][k]=(rand() %100)*(-1);
                             }
                             else
                             {
                                 matrix[i][k]=rand() %100;
                             }
                     }
          }
    }
    else
    {
        SetColor((ConsoleColor)12,(ConsoleColor)0);
        cout<<"Вводите числа от -100 до 100 по порядку"<<endl;
        SetColor((ConsoleColor)14,(ConsoleColor)0);
        cout<<"\nПример:Введеные таким образом числа\n1\n2\n3\n4\n5\n6\n7\n8\n9\nБудет выглядеть так:\n1 2 3\n4 5 6\n7 8 9"<<endl;
        SetColor((ConsoleColor)7,(ConsoleColor)0);
        for(int i=0; i<mat; i++)
        {
                for(int k=0; k<mat; k++)
                {
                        cin>>matrix[i][k];
                }
        }
    }
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    cout<<"Матрица заполнена: ";
    for(int i=0; i<mat; i++)
    {
            SetColor((ConsoleColor)10,(ConsoleColor)0);
            cout<<endl;
            for(int k=0; k<mat; k++)
            {
                    if((matrix[i][k]<10)&(matrix[i][k]>=0))
                    {
                                       cout<<"  "<<matrix[i][k]<<"|";
                    }
                    if((matrix[i][k]<0)&(matrix[i][k]>-10))
                    {
                        cout<<" "<<matrix[i][k]<<"|";
                    }
                    if((matrix[i][k]<100)&(matrix[i][k]>=10))
                    {
                        cout<<" "<<matrix[i][k]<<"|";
                    }
                    if((matrix[i][k]<=-10)&(matrix[i][k]>-100))
                    {
                        cout<<matrix[i][k]<<"|";
                    }
            }
    }
    cout<<endl;
    if(!pr)
    {
           cout<<"Введите вектор b"<<endl;
    }
    else
    {
        SetColor((ConsoleColor)12,(ConsoleColor)0);
        cout<<"Вектор b получается: ";
        SetColor((ConsoleColor)10,(ConsoleColor)0);
    }
    for(int i=0; i<mat; i++)
    {
            if(pr)
            {
                  x[i]=i+1;
            }
            else
            {
                cin>>x[i];
            }
    }
    for(int i=0; i<mat; i++)
    {
            for(int k=0; k<mat; k++)
            {
                    mau=(matrix[i][k]*x[k]);
                    sum=sum+mau;
            }
            b[i]=sum;
            sum=0;
    }
    cout<<endl;
    if(pr)
    {
          for(int i=0; i<mat; i++)
          {
                  cout<<b[i]<<endl;
          }
    }
    else
    {
        for(int i=0; i<mat; i++)
        {
                cout<<x[i]<<endl;
        }
    }///*
    /*matrix[0][0]=2;
    matrix[0][1]=4;
    matrix[0][2]=-4;
    matrix[0][3]=6;
    matrix[1][0]=1;
    matrix[1][1]=4;
    matrix[1][2]=2;
    matrix[1][3]=1;
    matrix[2][0]=3;
    matrix[2][1]=8;
    matrix[2][2]=1;
    matrix[2][3]=1;
    matrix[3][0]=2;
    matrix[3][1]=5;
    matrix[3][2]=0;
    matrix[3][3]=5;*/
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    cout<<"Матрица заполнена: ";
    for(int i=0; i<mat; i++)
    {
            SetColor((ConsoleColor)10,(ConsoleColor)0);
            cout<<endl;
            for(int k=0; k<mat; k++)
            {
                    if((matrix[i][k]<10)&(matrix[i][k]>=0))
                    {
                                       SetColor((ConsoleColor)13,(ConsoleColor)0);
                                       cout<<"  "<<matrix[i][k];
                                       SetColor((ConsoleColor)7,(ConsoleColor)0);
                                       cout<<"|";
                    }
                    if((matrix[i][k]<0)&(matrix[i][k]>-10))
                    {
                        SetColor((ConsoleColor)13,(ConsoleColor)0);
                        cout<<" "<<matrix[i][k];
                        SetColor((ConsoleColor)7,(ConsoleColor)0);
                        cout<<"|";
                    }
                    if((matrix[i][k]<100)&(matrix[i][k]>=10))
                    {
                        SetColor((ConsoleColor)13,(ConsoleColor)0);
                        cout<<" "<<matrix[i][k];
                        SetColor((ConsoleColor)7,(ConsoleColor)0);
                        cout<<"|";
                    }
                    if((matrix[i][k]<=-10)&(matrix[i][k]>-100))
                    {
                        SetColor((ConsoleColor)13,(ConsoleColor)0);
                        cout<<matrix[i][k];
                        SetColor((ConsoleColor)7,(ConsoleColor)0);
                        cout<<"|";
                    }
            }
    }//*/
    cout<<endl;
    SetColor((ConsoleColor)12,(ConsoleColor)0);
    cout<<"Итоговая матрица: ";
    for(int k=0; k<mat; k++)
    {
            for(int i=k+1; i<mat; i++)
            {
                    matrix[k][i]=matrix[k][i]/matrix[k][k];
            }
            for(int i=k+1; i<mat; i++)
            {
                    for(int j=k+1; j<mat; j++)
                    {
                            matrix[i][j]=matrix[i][j]-(matrix[i][k]*matrix[k][j]);
                    }
            }
    }
    for(int i=0; i<mat; i++)
    {
            SetColor((ConsoleColor)10,(ConsoleColor)0);
            cout<<endl;
            for(int k=0; k<mat; k++)
            {
                    if((matrix[i][k]<10)&(matrix[i][k]>=0))
                    {
                                       SetColor((ConsoleColor)13,(ConsoleColor)0);
                                       cout<<"  "<<matrix[i][k];
                                       SetColor((ConsoleColor)7,(ConsoleColor)0);
                                       cout<<"|";
                    }
                    if((matrix[i][k]<0)&(matrix[i][k]>-10))
                    {
                        SetColor((ConsoleColor)13,(ConsoleColor)0);
                        cout<<" "<<matrix[i][k];
                        SetColor((ConsoleColor)7,(ConsoleColor)0);
                        cout<<"|";
                    }
                    if((matrix[i][k]<100)&(matrix[i][k]>=10))
                    {
                        SetColor((ConsoleColor)13,(ConsoleColor)0);
                        cout<<" "<<matrix[i][k];
                        SetColor((ConsoleColor)7,(ConsoleColor)0);
                        cout<<"|";
                    }
                    if((matrix[i][k]<=-10)&(matrix[i][k]>-100))
                    {
                        SetColor((ConsoleColor)13,(ConsoleColor)0);
                        cout<<matrix[i][k];
                        SetColor((ConsoleColor)7,(ConsoleColor)0);
                        cout<<"|";
                    }
            }
    }
    SetColor((ConsoleColor)7,(ConsoleColor)0);
    cout<<endl;
    system("pause");
}
