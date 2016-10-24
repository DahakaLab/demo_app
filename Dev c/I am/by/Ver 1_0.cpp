#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int mat(int i, int y)
{
    int a[i][y];
    for(int gy = 0; gy<i; gy++)
    {
            for(int gi = 0; gi<y; gi++)
            {
                    a[gi][gy]=0;
            }
    }
    return a[i][y];
}

int ht()
{
    cout<<"BABURKA!!!";
}

int of()
{
    int o;
    cin>>o;
    ofstream save("I_am.txt");
    save<<o;
}

int in()
{
    int f;
    ifstream read("I_am.txt");
    read>>f;
    return f;
    
}

int main()
{
    cout<<"Dahaka_inc"<<endl<<endl<<"Dobro pozhalovat'!\nVvedi chislo ot 1 do 512:"<<endl;
    int x;
    cin>>x;
    if(x == 1)
    {
         of();
    }
    if(x==256)
    {
              cout<<"Vu ygadali chislo, poetomy ya prosto vuryblys'";
    }
    if(x==512)
    {
              int i, y,lk;
              cin>>i>>y;
              for(int gi = 0; gi<i; gi++)
              {
                      cout<<endl;
                      for(int gy = 0; gy<y; gy++)
                      {
                              cout<<mat(i,y);
                              ofstream save2("I_am.txt");
                              save2<<mat(i,y);
                      }
              }
    }
    if(x==5)
    {
            ht();
    }
    else
    {
        cout<<in();
    }
    getch();
}
