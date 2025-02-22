#include <iostream>

using namespace std;

int main()
{
    //c-uplata b-tip x-sifra v-koef
   int c,b;
   double zbir=1;
   double v;
   string x,h;
   cin>>c;
   double vn=0;
    int bn;

    while(cin>>x>>b>>v){
        zbir*=v;
        if(vn<v){
            vn=v;
            bn=b;
            h=x;
        }
        
    }
    double maxdobivka=zbir*c;
    cout<<h<<" "<<bn<<" "<<vn<<endl;
    cout<<maxdobivka;
    return 0;
}