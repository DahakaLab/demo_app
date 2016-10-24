#include <iostream>
#include <conio.h>

using namespace std;

int M(int N, int k)
{
    int x;
    x=(N-k)/2;
    return x;
}

int main()
{
    int A,N,k;
    cout<<"Lab 2 zadacha 17\nVvedite kol-vo vupyshenuh izdelii v marte i aprele:"<<endl;
    cin>>N;
    cout<<"Vvedite na skolko vupyshenuh izdelii v aprele bolshe chem marte:"<<endl;
    cin>>k;
    A=M(N,k)+k;
    if(N==(A+M(N,k)))
    cout<<"V marte izdelii vupysheno: "<<M(N,k)<<"\nV aprele izdelii vupysheno: "<<A;
    else
    cout<<"Nevernue dannue";
    getch();
}
