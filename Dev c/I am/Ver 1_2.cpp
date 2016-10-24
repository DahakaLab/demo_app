#include <iostream>
#include <windows.h>

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

int a(int x/*5*/, int y/**/)
{
    int m[x][y];
    int p=2;
    m[x][y]=p;
    return m[x][y];
}

int main(int argc, char *argv[])
{
    int x, y, i, k;
    i=k=0;
    x=10;
    y=10;
    while(i!=(x*x))
    {
               cout<<endl;
               while(k!=y)
               {
                 cout<<a(i,k)<<" ";
                 k++;
               }
               i++;
    }
    cout<<endl<<"Женя гусь гусь"<<endl;
    system("PAUSE");
}

