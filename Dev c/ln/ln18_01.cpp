#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    
    char c;
    cout<<"y-Exit"<<endl<<endl<<endl;
    do
    {
    ifstream f("ln16_1.txt");
    const int n=100;
    int m[n];
    int x;
    cin>>x;
    for(int i=0; i<n; i++)
    {
            f>>m[i];
    }
    
    for(int i=0; i<n; i++)
    {
            if(x==m[i])
                       cout<<"Chislo nahodotsya v "<<i+1<<" stroke"<<endl;
            else
                if(i==99)
                  cout<<"Chislo otsytstvuet"<<endl;
                  
    }cin>>c;
    }while(c!='y');
}
