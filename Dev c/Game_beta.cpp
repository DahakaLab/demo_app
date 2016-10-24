#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a;
    ifstream f("save.txt");
    f>>a;
    int s[a];
    for(int i=1; i<(a+1); i++)
    {
            f>>s[i];
    }
    for(int i=1; i<(a+1); i++)
    {
            cout<<s[i]<<endl;
    }
    system("pause");
}
