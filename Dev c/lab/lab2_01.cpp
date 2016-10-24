#include <iostream>
#include <conio.h>

using namespace std;

int C(int N, int k)
{
    int x;
    x=N/(k+1);
    return x;
}

int main()
{
    int N, k, t;
    cout<<"Lab 2 zadacha 10\nVvedite kol-vo stankov:"<<endl;
    cin>>N;
    cout<<"Vvedite vo skolko raz tokarnyh stankov bolshe chem sverilnyh:"<<endl;
    cin>>k;
    t=k*C(N,k);
    if(N==(t+C(N,k)))
                     cout<<"Sverilnyh stankov: "<<C(N,k)<<endl<<"Tokarnyh stankov: "
                                      <<t<<endl;
    else
        cout<<"Nevernoe kol-vo"<<endl;
    getch();
}
