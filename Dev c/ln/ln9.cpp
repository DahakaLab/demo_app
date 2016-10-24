#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout<<"Dahaka_inc"<<endl<<endl<<endl;
    int p, pp, z, o1, o2;
    o1 = o2 = 0;
    p=1;
    bool done;
    do
    {
        int x;
        char c;
        srand(time(0));
        int i = rand() %100;
        while (true)
        {
              z=p+1;
              pp=(z/2)*2;
              p=z;
              if(pp==z)
              {
                       cout<<"Igrok 1, vvedi chislo"<<endl;
              }
              else
              {
                  cout<<"Igrok 2, vvedi chislo"<<endl;
              }
              cout<<endl;
              cin>>x;
              if (x>i)
              cout<<"Moe menshe"<<endl<<endl;
              else
              {
                  if(x<i)
                  cout<<"Moe bolse"<<endl<<endl;
                  else
                  {
                      cout<<"Tu ygadal"<<endl<<endl;
                      if(pp==z)
                      {
                               cout<<"Pobedil 1"<<endl;
                               o1+=1;
                      }
                      else
                      {
                          cout<<"Pobedil 2 igrok"<<endl;
                          o2+=1;
                      }
                      break;
                  }
              }
        }
    cout<<"Schet:"<<endl<<"Igrok 1: "<<o1<<endl<<"Igrok 2: "<<o2<<endl<<"Eshe?  (a-aga)"<<endl;
    p+=1;
    cin>>c;
    cout<<endl;
    done = (c!='a');
    }while(!done);
}
