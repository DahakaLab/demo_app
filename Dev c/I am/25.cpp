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

int main(int argc, char *argv[])
{
    cout << "вот так" << endl;
    
    system("PAUSE");
    return 0;
}
