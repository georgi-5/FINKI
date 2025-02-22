#include <iostream>

using namespace std;

int main()
{
    int c,zbir=0,cifra=0,maxcifra=0;
    while(cin>>c){
        zbir=0+maxcifra;
        maxcifra=0;
        int num=c;
        while(num!=0){
        cifra=num%10;
        zbir+=cifra;
        num/=10;
        if(cifra>maxcifra){
            maxcifra=cifra;
        }
        }
        cout<<c<<": "<<zbir<<endl;
    }

    return 0;
}